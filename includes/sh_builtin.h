/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:05:22 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 19:05:23 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTIN_H
# define SH_BUILTIN_H

# include "sh_exec.h"

int			sh_e_run_built(t_sh *sh, t_simp_cmd *simp_cmd);

typedef int	(*t_sh_blt)(t_sh *sh, char **argv, char **envp);

int			sh_blt_echo(t_sh *sh, char **argv, char **envp);
int			sh_blt_cd(t_sh *sh, char **argv, char **envp);
int			sh_blt_env(t_sh *sh, char **argv, char **envp);
int			sh_blt_printenv(t_sh *sh, char **argv, char **envp);
int			sh_blt_setenv(t_sh *sh, char **argv, char **envp);
int			sh_blt_unsetenv(t_sh *sh, char **argv, char **envp);

t_sh_blt	sh_e_get_blt(char *bname);

#endif
