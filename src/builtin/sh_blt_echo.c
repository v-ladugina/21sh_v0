/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_blt_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:18:20 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 17:18:22 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_blt_echo(t_sh *sh, char **argv, char **envp)
{
	uint8_t op;
	int		i;

	(void)envp;
	(void)sh;
	if (!argv)
		return (1);
	op = 0;
	i = 1;
	if (argv[i] && !ft_strcmp(argv[i], "-n") && i++)
		op = 1;
	while (argv[i])
	{
		if (argv[i + 1])
		{
			ft_putstr(argv[i++]);
			ft_putchar(' ');
		}
		else
			break ;
	}
	if (argv[i])
		ft_putstr(argv[i]);
	if (!op)
		ft_putchar('\n');
	return (0);
}
