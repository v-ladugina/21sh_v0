/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:48:31 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:48:32 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_pipeline(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_PIPELINE)
	if (sh_p_match(p, &cast, TSBANG)) // TODO: TBD
	{
		if (sh_p_pipe_seq(p, SHP_CAST_L)) // TODO: or R
			PRET(1)
		PRET(0)
	}
	else if (sh_p_pipe_seq(p, SHP_CAST_L)) // TODO: or R
		PRET(1)
	else
		PRET(0)
}

int		sh_p_pipe_seq(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_PIPE_SEQ)
	if (sh_p_cmd(p, SHP_CAST_L) && sh_p_pipe_seq_sub(p, SHP_CAST_R))
		PRET(1)
	PRET(0)
}

int		sh_p_pipe_seq_sub(t_parser *p, t_btree **ast)
{
	t_list *back;
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_PIPE_SEQ_SUB)
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_match(p, NULL, TSO) // TODO: Recheck NULL
		&& sh_p_lbreak(p, NULL)
		&& sh_p_cmd(p, SHP_CAST_L)
		&& sh_p_pipe_seq_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	PRET(1)
}
