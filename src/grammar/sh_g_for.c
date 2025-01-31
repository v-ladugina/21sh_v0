/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_g_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:24:45 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 17:24:46 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern int 		g_g_putlev;

void			*sh_g_for_new(void)
{
	t_for	*for_clause;

	SHG_CHECK_MALL(for_clause);
	for_clause->name = NULL;
	for_clause->do_group = NULL;
	for_clause->lst_wordlist = NULL;
	return (for_clause);
}

void			*sh_g_for(t_btree *ast_for)
{
	t_for	*for_clause;
	t_btree	*wordlist;

	SHG_CHECK_AST(ast_for, SH_GR_FOR_CLAUSE)
	for_clause = sh_g_for_new();
	if (!ast_for->data || !ast_for->right) // TODO: if true, free for_clause
		return (NULL);
	for_clause->name = SHG_AST_TOK(ast_for)->val; // TODO: alloc mem
	//if (!(for_clause->do_group = sh_g_com_cmd(ast_for->right))) // TODO: free if true
	if (!(for_clause->do_group = sh_g_group(ast_for->right))) // TODO: free if true
		return (NULL);
	wordlist = ast_for->left;
	while (wordlist)
	{
		if (wordlist->data)
			SHG_LSTADD(for_clause, lst_wordlist, SHG_AST_TOK(wordlist)->val);
		wordlist = wordlist->right;
	}
	return (for_clause);
}

void			sh_g_for_put(void*g, int op)
{
	t_for		*for_clause;
	t_com_cmd	*do_group;

	if (!g)
		return ;
	g_g_putlev++;
	SHG_PUT_CASTVAR(for_clause, g, t_for*, op)
	do_group = for_clause->do_group;
	SHG_PUT_PRINTF("for_clause:\n", g_g_putlev++);
	SHG_PUT_PRINTF("name: ", g_g_putlev);
	ft_putendl(for_clause->name->str);
	SHG_PUT_PRINTF("wordlist:\n", g_g_putlev);
	ft_lstiter(for_clause->lst_wordlist, &sh_g_wordput);
	SHG_PUT_PRINTF("do_group:\n", g_g_putlev);
	sh_g_com_cmd_put(do_group, 0);
	g_g_putlev -= 2;
}
