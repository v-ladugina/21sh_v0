/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_xp_scmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:21:27 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 17:21:29 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int 	sh_xp_bq(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dstr	*word;
	t_sh	*nsh;
	char 	*script;
	int 	off;

	DF0
	word = words->a[*i];
	if (word->str[*j] != '`')
		return (0);
	off = (*j)++;
	while (word->str[*j] && word->str[*j] != '`')
		(*j)++;
	if (word->str[*j] != '`')
		return (-1);
	script = ft_strndup(word->str + off + 1, *j - off - 1);
	ft_dstrdel_n(word, off, *j - off + 1);
	*j = off;
	nsh = sh_sh_clone(sh, SH_MODE_SCMD);
	sh_script_run(nsh, script);
	ft_dstrins_str(word, *j, nsh->sub_out->str);
	*j += ft_strlenz(nsh->sub_out->str);
	// TODO: free nsh
	FT_MEMDEL(script)
	sh_sh_free(&nsh);
	return (1);
}

int 	sh_xp_scmd(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dstr	*word;
	t_sh	*nsh;
	char 	*script;
	t_lex	*lex;

	DF0
	word = words->a[*i];
	if (ft_strncmp(word->str + *j, "$(", 2))
		return (0);
	sh_lex_init(&lex, word->str + *j);
	if (!sh_lex_seek_scmd(lex, 0)) // TODO: recheck
		return (1);
	script = ft_strndup(lex->in->str + 2, lex->i - 3);
	ft_printf("BQ Script: <%s>\n", script);
	ft_dstrdel_n(word, *j, lex->i);
	nsh = sh_sh_clone(sh, SH_MODE_SCMD);
	ft_printf("sh cloned !\n");
	sh_script_run(nsh, script);
	ft_printf("sh scr run !\n");
	ft_printf(C_GRN"RES SUBST:\n%s\n-----------\n"T_END, nsh->sub_out->str);
	ft_dstrins_str(word, *j, nsh->sub_out->str);
	*j += ft_strlenz(nsh->sub_out->str);
	FT_MEMDEL(script)
	sh_lex_free(&lex);
	sh_sh_free(&nsh);
	return (1);
}
