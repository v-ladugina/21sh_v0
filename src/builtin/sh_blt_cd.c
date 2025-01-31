/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_blt_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:18:10 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 17:18:11 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <sys/stat.h>

int		sh_blt_cd_setwd(t_sh *sh, char *dir)
{
	char 	*cwd;

	if (!sh || !dir)
		return (1);
	if (!(cwd = ft_getcwd()))
		return (1);
	if (access(dir, F_OK))
		FT_INST_RET(1, FT_STDEPF("ftsh: cd: %s: No such file or directory !\n", dir))
	else if (ft_stat_is(dir, S_IFDIR) != OK)
		FT_INST_RET(1, FT_STDEPF("ftsh: cd: %s: Not a directory !\n", dir))
	else if (access(dir, X_OK))
		FT_INST_RET(1, FT_STDEPF("ftsh: cd: %s: Permission denied !\n", dir))
	else if (chdir(dir))
		FT_INST_RET(1, FT_STDEPF("ftsh: cd: %s: Unable to change dir !\n", dir))
	ft_tabins(sh->var, ft_tabrow_set(-1, "PWD", dir, SH_VO_GLO), 1);
	ft_tabins(sh->var, ft_tabrow_set(-1, "OLDPWD", cwd, SH_VO_GLO), 1);
	return (0);
}

int		sh_blt_cd(t_sh *sh, char **argv, char **envp)
{
	int		ac;
	char	*dir;

	(void)envp;
	if (!argv)
		return (1);
	if ((ac = ft_arr_len((void**)argv)) > 2 || ac < 1)
		FT_STDE_RET(-1, "ftsh: cd: Too many arguments !");
	if (ac == 1)
	{
		if (!(dir = sh_env_getval(envp, "HOME")))
			FT_STDE_RET(1, "ftsh: cd: HOME not set !");
		return (sh_blt_cd_setwd(sh, dir));
	}
	else
	{
		dir = argv[1];
		if (!ft_strcmp(argv[1], "-"))
		{
			if (!(dir = sh_env_getval(envp, "OLDPWD")))
				FT_STDE_RET(1, "ftsh: cd: OLDPWD not set !");
			ft_putendl(dir);
		}
		return (sh_blt_cd_setwd(sh, dir));
	}
}
