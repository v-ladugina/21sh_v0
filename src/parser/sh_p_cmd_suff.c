/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_cmd_suff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:46:51 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:46:52 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_cmd_suff(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_CMD_SUFF)
	back = p->tlook;
	if (sh_p_match(p, &cast, TSTOK_WORD)
		&& sh_p_cmd_suff_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	ft_btreefree(&(cast->right), (t_free)&sh_lex_tok_tfree);
	if (sh_p_io_redir(p, SHP_CAST_L)
		&& sh_p_cmd_suff_sub(p, SHP_CAST_R))
		PRET(1)
	PRET(0)
}
int		sh_p_cmd_suff_sub(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_CMD_SUFF_SUB)
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_io_redir(p, SHP_CAST_L)
		&& sh_p_cmd_suff_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	ft_btreefree(&(cast->right), (t_free)&sh_lex_tok_tfree);
	if (sh_p_match(p, &cast, TSTOK_WORD) // TODO
		&& sh_p_cmd_suff_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	PRET(1)
}
