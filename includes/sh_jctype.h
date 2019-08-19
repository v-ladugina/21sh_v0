#ifndef SH_JCTYPE_H
#define SH_JCTYPE_H

/**
 * pid			:
 * done			: true if process has completed
 * stopped		: true if process has stopped
 * status		: reported status value
 */
typedef struct	s_process {
	pid_t			pid; /* process ID */
	char			done; /* true if process has completed */
	char			stopped; /* true if process has stopped */
	int				status; /* reported status value */
}				t_process;

/* A job is a pipeline of processes. */
/**
 * ind			: job index
 * pgid			: process group ID (pgid)
 * notified		: true if user told about stopped job
 */
typedef struct	s_job
{
	int				ind;
	pid_t			pgid;
	char			notified;
	t_termios		*tmodes;
	t_list			*process;
	char 			bg;
	int 			done;
	int				sep_ao;
}				t_job;

/**
** cind			: current index (init :: -1)
** jobs			: list of jobs (init :: NULL)
** cjob			: current job being processed (init :: NULL)
*/
typedef struct	s_jcon
{
	int 		cind;
	t_list		*jobs;
	t_job		*cjob;
//	int 		jlev;
}				t_jcon;

#endif
