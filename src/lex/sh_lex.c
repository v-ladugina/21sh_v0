//
// Created by xbluecode on 24.05.19.
//

#include "libft.h"
#include "sh_lex.h"

t_lex		g_lex;

t_lex 		sh_lex(void)
{
	return (g_lex);
}

int 		sh_lex_init(t_lex **plex, char *input)
{
	if (!input || !(*plex = (t_lex*)ft_memalloc(sizeof(t_lex))))
		return (-1);
	(*plex)->in = ft_dstrnew_str(input);
	(*plex)->i = 0;
	(*plex)->scope = ft_dstrnew_max(1);
	(*plex)->st = TSNONE;
	(*plex)->tlst = NULL;
	(*plex)->toff = NULL;
	return (0);
}

int 		sh_lex_free(t_lex **plex)
{
	ft_dstrfree(&(*plex)->in);
	ft_dstrfree(&(*plex)->scope);
	ft_lst_free(&(*plex)->tlst, (void(*)(void**))(&sh_lex_tok_free));
	return (0);
}

int 		sh_lex_start(t_lex *lex)
{
	sh_lex_seek(lex, 1);
	return (0);
}