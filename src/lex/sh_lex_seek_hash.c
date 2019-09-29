/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_hash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:43:00 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:43:05 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int 	sh_lex_seek_hash(t_lex *lex, int op)
{
	int clen;

	(void)op;
	if (lex->in->str[lex->i] != '#')
		return (0);
	clen = 1;
	while (lex->in->str[lex->i + clen] != '\n')
		clen++;
	ft_dstrdel_n(lex->in, lex->i, clen);
	return (1);
}
