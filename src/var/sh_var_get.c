/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_var_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:01:04 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 19:01:06 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftsh.h"

char	*sh_var_getval(t_table *var, char *name)
{
	t_trow	trow;

	trow = ft_tabget_n(var, name);
	return (trow.value);
}
