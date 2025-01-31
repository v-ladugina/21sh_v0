/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_rw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:44:23 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:44:25 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

char 	*g_res_words[] =
		{
		"if",
		"then",
		"else",
		"elif",
		"fi",
		"do",
		"done",
		"case",
		"esac",
		"while",
		"until",
		"for",
		"in",
		"!",
		"{",
		"}",
		NULL
		};

int		sh_lex_seek_rw(t_token *token, int ctx)
{
	int		i;

	if (!token || token->t != TSTOK || ctx != TCTX_FIRSTW)
		return (0);
	i = -1;
	while (g_res_words[++i] && ft_strcmp(g_res_words[i], token->val->str))
		;
	if (!g_res_words[i])
		return (0);
	token->t = TSRW + i + 1;
	return (1);
}
