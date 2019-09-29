/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:47:36 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:47:38 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_cb_group(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_CB_GROUP)
	/*
	return (sh_p_match(p, ast, TSCBL)
		&& sh_p_comp_list(p, ast)
		&& sh_p_match(p, ast, TSBR));
	 */
	if (sh_p_match(p, NULL, TSCBL) // TODO: Recheck NULL
		&& sh_p_comp_list(p, SHP_CAST_L)
		&& sh_p_match(p, NULL, TSCBR)) // TODO: Recheck NULL
		PRET(1);
	PRET(0)
}

int		sh_p_do_group(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_DO_GROUP)
	/*
	return (sh_p_match(p, ast, TSCBL)
		&& sh_p_comp_list(p, ast)
		&& sh_p_match(p, ast, TSBR));
	 */
	if (sh_p_match(p, NULL, TSRW_DO) // TODO: Recheck NULL
		&& sh_p_comp_list(p, SHP_CAST_L)
		&& sh_p_match(p, NULL, TSRW_DONE)) // TODO: Recheck NULL
		PRET(1);
	PRET(0)
}
