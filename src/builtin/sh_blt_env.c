/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_blt_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:18:26 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 17:18:28 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_blt_setenv(t_sh *sh, char **argv, char **envp)
{
	int ac;
	int m;

	(void)envp;
	if (!sh || !argv)
		return (1);
	ac = ft_arr_len((void**)argv);
	if (ac != 3 && ac != 4)
		FT_INST_RET(1, FT_STDEPF("ftsh: setenv: Bad arguments number !\n", NULL))
	if (!sh_tok_isname_till(argv[1], '\0'))
		FT_INST_RET(1, FT_STDEPF("ftsh: setenv: %s: Bad var name !\n", argv[1]))
	m = !argv[3] ? 0 : ft_atoi(argv[3]);
	ft_tabins(sh->var, ft_tabrow_set(-1, argv[1], argv[2], SH_VO_GLO), m);
	return (0);
}

int		sh_blt_unsetenv(t_sh *sh, char **argv, char **envp)
{
	int ac;

	(void)envp;
	if (!sh || !argv)
		return (1);
	ac = ft_arr_len((void**)argv);
	if (ac < 2)
	FT_INST_RET(1, FT_STDEPF("ftsh: unsetenv: Bad arguments number !\n", NULL))
	ac = 0;
	while (argv[++ac])
		ft_tabdel_n(sh->var, argv[ac]);
	return (0);
}

int		sh_blt_printenv(t_sh *sh, char **argv, char **envp)
{
	(void)sh;
	(void)argv;
	if (!sh || !envp)
		return (1);
	ft_arr_print(envp, ft_arr_len((void**)envp));
	return (0);
}

/*
**int			sh_blt_env(t_sh *sh, char **argv, char **envp)
**{
**	return (0);
**}
*/
