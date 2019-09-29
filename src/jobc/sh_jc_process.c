/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jc_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:32:45 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:32:46 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void			sh_jcp_print(t_process *p)
{
	if (!p)
		return ;
	ft_printf(C_YLW"-> process: pid=%d | stat=%d | d(%d) s(%d)\n"T_END,
			p->pid, p->status, p->done, p->stopped);
}

void			sh_jcp_lstput(t_list *plist)
{
	if (!plist)
		return ;
	ft_putchar('\n');
	sh_jcp_print((t_process*)plist->content);
}
