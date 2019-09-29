/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_comp_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:47:01 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:47:03 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				sh_p_comp_list(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_COMP_LIST)
	if (sh_p_lbreak(p, NULL) && sh_p_term(p, SHP_CAST_L))
	{
		sh_p_sep(p, SHP_CAST_R);
		PRET(1)
	}
	PRET(0)
}
