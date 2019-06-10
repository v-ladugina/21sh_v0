//
// Created by xbluecode on 08.06.19.
//

#include "libft.h"
#include "sh_lex.h"

int			sh_lex_seek_hd(t_lex *lex, int op)
{
	char	*hd_key;
	char	*hd_val;
	int 	hd_klen;
	int		nl;

	if (ft_strncmp(lex->in->str + lex->i, "<<", 2))
		return (0);
	lex->i += 2;
	hd_key = ft_strdup_cond(lex->in->str + lex->i, &ft_isalnum);
	hd_klen = ft_strlenz(hd_key);
	nl = ft_strichr(lex->in->str + lex->i, '\n');
	hd_val = sh_lex_seek_hd_getval(lex, hd_key,
		lex->i + ft_strichr(lex->in->str + lex->i, '\n') + 1);
	ft_dstrdel_n(lex->in, (lex->i -= 2), hd_klen + 2); // Not sure
	ft_printf("HEREDOC:\nKEY:\n%s\nVAL:\n%s\n", hd_key, hd_val); // needs to be stored !!!
	lex->st = TSL2;
	return (1);
}

char 		*sh_lex_seek_hd_getval(t_lex *lex, char *hd_key, ssize_t off)
{
	int		hd_klen;
	ssize_t	i;
	char 	*hd_val;
	int 	hd_vlen;

	i = off;
	hd_vlen = 0;
	hd_klen = ft_strlenz(hd_key);
	while (ft_strncmp(lex->in->str + i, hd_key, hd_klen)
		|| lex->in->str[i + hd_klen] != '\n')
		if (!(i = ft_strichr(lex->in->str + off + hd_vlen, '\n')))
			return (NULL);
		else
			hd_vlen += i + 1;
	hd_val = ft_strndup(lex->in->str + off, hd_vlen);
	ft_dstrdel_n(lex->in, off, hd_vlen);
	return (hd_val);
}