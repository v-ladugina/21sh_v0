/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_bs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:42:44 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:42:46 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int 		sh_lex_seek_escape(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] == '\\' && lex->in->str[lex->i + 1] != '\n')
	{
	    /*
		if (op == 1)
			ft_dstrdel_n(lex->in, lex->i++, 1);
		else
			lex->i += 2;
		return (1);
	     */
        //ft_dstrdel_n(lex->in, lex->i++, 1);
        lex->i += 2;
        return (1);
	}
	return (0);
}

int 		sh_lex_seek_join(t_lex *lex, int op)
{

	(void)op;
	if (lex->in->str[lex->i] == '\\' && lex->in->str[lex->i + 1] == '\n')
	{
		ft_dstrdel_n(lex->in, lex->i, 2);
        ft_dstrins_ch(lex->scope, -1, RL_SCP_JOIN);
		return (1);
	}
	return (0);
}

int 		sh_lex_seek_nl(t_lex *lex, int op)
{

	(void)op;
	if (lex->in->str[lex->i] != '\n')
		return (0);
	lex->st = TSNL;
	lex->i++;
	return (1);
}
