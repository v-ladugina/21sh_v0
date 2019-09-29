/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:00:46 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 19:00:47 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

char 	*sh_env_getval(char **envp, char *name)
{
	int		i;
	int		eqi;

	if (!envp || !name)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		if ((eqi = ft_strichr(envp[i], '=')) < 0)
			eqi = ft_strlen(envp[i]);
		if (ft_strncmp(envp[i], name, eqi))
			continue;
		if (envp[i][eqi] == '=')
			return (envp[i] + eqi + 1);
		else
			return (envp[i] + eqi);
	}
	return (NULL);
}
