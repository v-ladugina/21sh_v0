/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_e_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:19:08 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 17:19:09 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <sys/stat.h>

char		*g_bnames[] = {
	"echo",
	"cd",
	"printenv",
	"setenv",
	"unsetenv",
	NULL
};

t_sh_blt	g_blts[] = {
	&sh_blt_echo,
	&sh_blt_cd,
	&sh_blt_printenv,
	&sh_blt_setenv,
	&sh_blt_unsetenv,
	NULL
};

t_sh_blt	sh_e_get_blt(char *bname)
{
	int i;

	if ((i = sh_e_check_built(bname)) < 0)
		return (NULL);
	return (g_blts[i]);
}

int			sh_e_check_exec(char *cmd_name)
{
	char *tail;

	if (!(tail = ft_strchr_inv(cmd_name, '/')) || !(++tail))
		tail = cmd_name;
	if (ft_stat_is(cmd_name, S_IFDIR) == OK)
	{
		ft_dprintf(2, C_RED"ftsh: %s: is a directory !\n"T_END, tail);
		return (126);
	}
	if (access(cmd_name, F_OK))
	{
		ft_dprintf(2, C_RED"ftsh: %s: Command not found !\n"T_END, tail);
		return (126);
	}
	else if (access(cmd_name, X_OK))
	{
		ft_dprintf(2, C_RED"ftsh: %s: Permission denied !\n"T_END, tail);
		return (126);
	}
	return (OK);
}

int			sh_e_check_built(char *cmd_name)
{
	int i;

	if (!cmd_name)
		return (-1);
	i = -1;
	while (g_bnames[++i])
		if (!ft_strcmp(g_bnames[i], cmd_name))
			break ;
	if (g_bnames[i])
		return (i);
	return (-1);
}
