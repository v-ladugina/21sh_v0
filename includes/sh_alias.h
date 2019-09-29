/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_alias.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:05:06 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 19:05:08 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ALIAS_H
# define SH_ALIAS_H

# include <libft.h>

# define SH_ALS_HTSIZE 48

t_hset		*sh_als(void);
int			sh_als_init(void);

int			sh_als_add(t_hset *als, char *key, char *val);
int			sh_als_rem(t_hset *als, char *key);

int			sh_als_print(t_hset *als);
void		sh_als_print_ent(t_list *als);

#endif
