/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_and_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:46:30 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:46:32 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_and_or(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_AND_OR)
	if (sh_p_pipeline(p, SHP_CAST_L) && sh_p_and_or_sub(p, SHP_CAST_R))
		PRET(1)
		//return (sh_p_lookshift(p));
	PRET(0)
}
int		sh_p_and_or_sub(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_AND_OR_SUB)
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_match(p, &cast,TSA2)) // TODO: TBD
	{
		if (sh_p_lbreak(p, NULL) && sh_p_pipeline(p, SHP_CAST_L)
			&& sh_p_and_or_sub(p, SHP_CAST_R))
			PRET(1)
		PRET(0)
	}
	if (sh_p_match(p, &cast, TSO2)) // TODO: TBD
	{
		if (sh_p_lbreak(p, NULL) && sh_p_pipeline(p, SHP_CAST_L)
			&& sh_p_and_or_sub(p, SHP_CAST_R))
			PRET(1)
		PRET(0)
	}
	PRET(1)
}
