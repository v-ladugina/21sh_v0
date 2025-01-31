/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_scope_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:57:59 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:58:01 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftsh.h"

extern t_rl g_rl;

int			rl_scope_prompt(char *str) {
	int i;

	g_rl.plen = 0;
	if (*str == RL_SCP_START)
		return (rl_scope_prompt_ps());
	i = -1;
	//(void)str;
	while (str[++i])
		g_rl.plen += ft_printf("%s ", g_rl_scope_prompt[(int) str[i]]);
	ft_putstr("> ");
	g_rl.plen += 2;
//	ft_printf("plen: %d\n", g_rl.plen);
	return (0);
}

int 		rl_scope_prompt_ps(void)
{
	char	*ps1;
	t_dstr	*prompt;
	int 	i;

	g_rl.plen = 0;
	if (!(ps1 = sh_var_getval(sh_sh()->var, "PS1")))
		ps1 = SH_VV_PS1;
	//g_rl.plen += ft_printf("%s", ps1);
	prompt = ft_dstrnew_str(ps1);
	i = -1;
	while (prompt->str[++i])
	{
		rl_scope_prompt_ps_h(prompt, i);
		rl_scope_prompt_ps_u(prompt, i);
		rl_scope_prompt_ps_w(prompt, i);
	}
	g_rl.plen += ft_printf("%s", prompt->str);
	ft_dstrfree(&prompt);
	return (OK);
}

