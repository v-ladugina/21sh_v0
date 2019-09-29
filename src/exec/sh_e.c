/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:18:56 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 17:18:59 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			sh_e_com_cmds(t_sh *sh, void *gr)
{
	t_com_cmds	*com_cmds;
	t_list		*com_cmd;
	int 		ret;

	DF0
	if (!sh || !gr)
		return (0);
	com_cmds = (t_com_cmds*)gr;
	com_cmd = com_cmds->lst_com_cmd;
	ret = 0;
	while (com_cmd
	{
		ret = sh_e_com_cmd(sh, com_cmd->content);
		com_cmd = com_cmd->next;
	}
	return (ret);
}

/*
** map to group exec (subsh)
*/

int			sh_e_com_cmd(t_sh *sh, void *gr)
{
	t_list		*and_or_lst;
	t_com_cmd	*com_cmd;
	t_sh		*nsh;
	int 		ret;

	DF0
	if ((ret = 0) || !sh || !gr)
		return (0);
	com_cmd = (t_com_cmd*)gr;
	and_or_lst = com_cmd->lst_and_or;
	nsh = (com_cmd->gr == SH_GR_SUBSH) ? sh_sh_clone(sh, SH_MODE_SSH) : NULL;
	while (and_or_lst)
	{
		ft_dstrdel_n(com_cmd->sep, -1, 1);
		ret = sh_e_and_or(nsh ? nsh : sh, and_or_lst->content);
		and_or_lst = and_or_lst->next;
	}
	sh_sh_free(&nsh);
	return (ret);
}

int 		sh_e_and_or(t_sh *sh, void *gr)
{
	t_and_or	*and_or;
	t_list		*pipe_lst;
	int 		ret;
	int 		sep_ao;

	DF0
	if ((ret = 0) || !sh || !gr)
		return (0);
	and_or = (t_and_or*)gr;
	pipe_lst = and_or->lst_pipe;
	while (pipe_lst)
	{
		sep_ao = ft_dstrget_ch(and_or->sep, -1);
		ft_dstrdel_n(and_or->sep, -1, 1);
		ret = sh_e_pipe(sh, pipe_lst->content);
		if ((ret && sep_ao == TSA2) || (!ret && sep_ao == TSO2))
			break;
		pipe_lst = pipe_lst->next;
	}
	return (ret);
}

