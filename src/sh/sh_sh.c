/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:59:48 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:59:50 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <signal.h>

extern t_sh		*g_sh;

t_sh 			*sh_sh(void)
{
	return (g_sh);
}

int 			sh_sh_init(t_sh **sh, char **envp, int mode) // init mode (subsh ...)
{
	if (!sh)
		return (KO);
	DF0
	*sh = ft_memalloc(sizeof(t_sh));
	(*sh)->mode = mode;
	(*sh)->jc = NULL;
	(*sh)->pgid = -1;
//	(*sh)->tmodes = NULL;
	(*sh)->term_std = STDIN_FILENO;
	(*sh)->inter = isatty((*sh)->term_std);
	sh_var_start(&(*sh)->var, envp);
	//(*sh)->stdi = dup(STDIN_FILENO);
	//(*sh)->stdo = dup(STDOUT_FILENO);
	sh_bin_init(&(*sh)->bin_ht, &(*sh)->bin_nl);
	sh_bin_update((*sh)->bin_ht, (*sh)->bin_nl, sh_var_getval((*sh)->var, "PATH"));
	(*sh)->nest = 0;
	if (BIT_IS(mode, SH_MODE_TER) && (*sh)->inter)
	{
		while (tcgetpgrp ((*sh)->term_std) != ((*sh)->pgid = getpgrp ()))
			kill (- (*sh)->pgid, SIGTTIN);
		//signal (SIGINT, SIG_IGN);
		//signal (SIGQUIT, SIG_IGN);
		//signal (SIGTSTP, SIG_IGN);
		//signal (SIGTTIN, SIG_IGN);
		//signal (SIGTTOU, SIG_IGN);
		//signal (SIGCHLD, SIG_IGN);
		(*sh)->pgid = getpid();
		if (setpgid((*sh)->pgid, (*sh)->pgid) < 0)
		{
			ft_printf("Couldn't put the shell in its own process group !\n");
			exit(1);
		}
		tcsetpgrp((*sh)->term_std, (*sh)->pgid);
		//tcgetattr((*sh)->term_std, &(*sh)->tmodes);
		sh_termconfig_init(&(*sh)->term);
		(*sh)->jc = sh_jc_new();
		ft_printf(C_GRN"Interactive Term initialized ^ ^\n"T_END);
	}
	(*sh)->sub_pipe = NULL;
	(*sh)->sub_out = NULL;
	return (OK);
}

t_sh 			*sh_sh_clone(t_sh *sh, int mode)
{
	t_sh	*nsh;

	if (!sh)
		return (NULL);
	nsh = ft_memalloc(sizeof(t_sh));
	if (mode == SH_MODE_SSH || mode == SH_MODE_SCMD)
	{
		nsh->mode = sh->mode;
		BIT_MSET(nsh->mode, SH_MODE_M, mode);
		nsh->jc = NULL;
		nsh->var = ft_tabdup(sh->var);
		nsh->inter = 0;
		nsh->nest = sh->nest; // TODO: recheck
		nsh->bin_ht = sh->bin_ht; // TODO: duplicate or init
		nsh->bin_nl = sh->bin_nl; // TODO: duplicate ot init
		if (mode == SH_MODE_SCMD)
		{
			nsh->sub_pipe = ft_memalloc(2 * sizeof(int));
			nsh->sub_out = ft_dstrnew_max(2);
		}
	}
	return (nsh);
}

int 			sh_sh_free(t_sh **sh)
{
	//DF0
	if (!sh || !*sh)
		return (1);
	// TODO: free jobc
	if (!BIT_IS((*sh)->mode, SH_MODE_SSH) && !BIT_IS((*sh)->mode, SH_MODE_SCMD))
	{ // TODO: deprecate condition if bins are duplicated by clone
		ft_hset_free(&(*sh)->bin_ht);
		ft_dastrfree(&(*sh)->bin_nl);
	}
	ft_tabfree(&(*sh)->var);
	FT_MEMDEL((*sh)->sub_pipe);
	ft_dstrfree(&(*sh)->sub_out);
	FT_MEMDEL(*sh)
	return (0);
}
