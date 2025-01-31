/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jc_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <abbesbes@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:32:55 by abbesbes          #+#    #+#             */
/*   Updated: 2019/09/28 18:32:56 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <signal.h>

int 			sh_jc_put_in_forg(t_sh *sh, int cont)
{
	DF0
	tcsetpgrp(sh->term_std, sh->jc->cjob->pgid);
	if (cont)
	{
		tcsetattr (sh->term_std, TCSADRAIN, sh->jc->cjob->tmodes);
		if (kill(-sh->jc->cjob->pgid, SIGCONT) < 0)
			ft_printf("err: kill [SIGCONT]\n");
	}
	sh_jc_wait(sh->jc, sh->jc->cjob);
	tcsetpgrp(sh->term_std, sh->pgid);
	tcgetattr(sh->term_std, sh->jc->cjob->tmodes);
	tcsetattr(sh->term_std, TCSADRAIN, &sh->tmodes);
	sh->jc->cind--;
	sh->jc->jobs = sh->jc->jobs->next;
	sh->jc->cjob = sh->jc->jobs ? (t_job*)sh->jc->jobs->content : NULL;
	return (0);
}

int 			sh_jc_put_in_back(t_sh *sh, int cont)
{
	DF0
	if (cont)
	{
		if (kill (-sh->jc->cjob->pgid, SIGCONT) < 0)
			ft_printf("kill (SIGCONT)");
	}
	return (0);
}
