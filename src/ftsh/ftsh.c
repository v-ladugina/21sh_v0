/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:22:19 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 17:22:20 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <fcntl.h>

t_sh	*g_sh;

int		sh_file_run(char *filename, char **envp)
{
	t_dstr	*dscript;
	t_sh	*sh;
	int		ret;

	DF0
	if (!(dscript = ft_read_file(filename)))
		return (KO);
	sh_sh_init(&sh, envp, SH_MODE_SCR); // TODO: specify correct sh-mode
	ret = sh_script_run(sh, dscript->str);
	ft_dstrfree(&dscript);
	sh_sh_free(&sh);
	return (ret);
}

/*
** TODO: add sh as param (subsh ...)
*/
int		sh_script_run(t_sh *sh, char *script)
{
	t_lex		*lex;
	t_com_cmds	*com_cmds;
	int 		ret;

	if (!script)
		return (1);
	sh_lex_init(&lex, script);
	if (sh_lex_start(lex) == KO)
		FT_INST_RET(KO, sh_lex_free(&lex));
	if (!lex->tlst)
		FT_INST_RET(KO, sh_lex_free(&lex));
	if (!(com_cmds = sh_p_start(lex)))
	{
		sh_lex_free(&lex);
		sh_g_com_cmds_free((void**)&com_cmds);
		return (KO);
	}
	sh_lex_free(&lex);
	ret = sh_e_com_cmds(sh, com_cmds);
	sh_g_com_cmds_free((void**)&com_cmds);
	return (ret);
}

int		sh_inter_read(char **line)
{
	*line = rl_start();
	return (0);
}

int		sh_term_run(char **envp)
{
	char	*line;
	int 	ret;

	DF0
	sh_sh_init(&g_sh, envp, SH_MODE_TER); // TODO: specify correct sh-mode
	rl_hist_init(RL_HIS_FILENAME);
	rl_hist_upload();
	rl_hist_print();
	line = NULL;
	ret = 0;
	while (1)
	{
		ret = 0;
		sh_inter_read(&line);
		if (!ft_strncmp("exit", line, 4))
			 break;
		rl_hist_add(line);
		ret = sh_script_run(g_sh, line);
		FT_MEMDEL(line)
	}
	FT_MEMDEL(line)
	rl_hist_save();
	rl_hist_free();
	return (ret);
}

int		main(int ac, char **av, char **envp)
{
	int sh_est;

	if (ac > 1)
		sh_est = (sh_file_run(av[1], envp));
	else
	{
		sh_est = sh_term_run(envp);
		sh_termconfig_reset(&sh_sh()->term);
	}
	system("leaks -q 21sh");
	return (sh_est);
}

/*
**
**	ft_tabins(sh_var(), ft_tabrow_set(0, "NEW", "nvalue120", 0), 0);
**	ft_tabput(sh_var(), "=");
**
**	sh_bin_init(sh_bin_ptr());
**	sh_bin_update(sh_bin(), sh_var_getval("PATH"));
**	ft_printf("Bins Updated !!!\n");
**	ft_printf("echo :: %s\n", sh_bin_getpath(sh_bin(), "echo"));
**
**	sh_als_init();
**	sh_als_add(sh_als(), "al1", "cd ");
**	sh_als_add(sh_als(), "al2", "cd ; al2");
**	sh_als_add(sh_als(), "al3", "al1 ; al2");
**
**
**	sh_als_add(sh_als(), "AA", "BB");
**	sh_als_add(sh_als(), "BB", "CC");
**	sh_als_add(sh_als(), "CC", "AA");
*/
