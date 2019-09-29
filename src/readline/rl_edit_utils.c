/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_edit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:56:19 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:56:20 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_get_header(void)
{
	int slen;

	slen = ft_strlenz(g_rl.txt->a[g_rl.cl]->str);
	return ((slen + g_rl.plen) / g_rl.wc + ((slen + g_rl.plen) % g_rl.wc ? 1 : 0));
}
