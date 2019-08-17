// header

#include "ftsh.h"
#include <fcntl.h>

t_term	g_term;
t_sh	*g_sh;


int		sh_file_run(char *filename)
{
	t_dstr	*dscript;
	char 	c;
	int 	fd;

	ft_putendl(filename);
	dscript = ft_dstrnew_max(128);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (1);
	while (!(c = 0) && read(fd, &c, 1))
		ft_dstrins_ch(dscript, -1, c);
	return (sh_script_run(dscript->str));
}

int		sh_script_run(char *script) // TODO: add sh as param (subsh ...)
{
	t_lex *lex;
	t_com_cmds *com_cmds;

	ft_printf(C_CYN"\nScript:\n-------\n%s\n-------\n\n"T_END, script);
	if (!script)
		return (1);
	sh_lex_init(&lex, script);
	sh_lex_start(lex);
	if (!(com_cmds = sh_p_start(lex)))
		return (KO);
	return (sh_e_com_cmds(g_sh, com_cmds, 0));
}

int		sh_inter_read(char **line)
{
	//(void)line;
	//prompt_display();
	//signal(SIGINT, sighand_parent);
	//get_inline(line);
	*line = rl_start();
	return (0);
}

int		sh_term_run(void)
{
	char	*line;
//	t_lex	*lex;

	//init_hist
	//rl_hist_init("/home/xbluecode/ft/ftsh/history/.ftsh_history"); // replace arg by _getpath
	sh_sh_init(&g_sh);
	rl_hist_init(RL_HIS_FILENAME);
	rl_hist_upload();
	rl_hist_print();
	sh_termconfig_init();
	line = "";
	while (ft_strcmp(line, "exit\n"))
	{
		sh_inter_read(&line);
	//	ft_printf("in run: line: <%s>\n", line);
		rl_hist_add(line);
		if (!ft_strcmp("exit", line))
			return (0);
		sh_script_run(line);
		/*
		sh_lex_init(&lex, line);
		sh_lex_start(lex);
		sh_p_start(lex);
		 */
		//rl_cleanup();
		//if (sh_script_run(line) == EXIT)
		//{
		//	ft_memdel((void**)&line);
		//	return (OK);
		//}
		//ft_memdel((void**)&line);
	}
	rl_hist_save();
	return (0);
}

int		main(int ac, char **av, char **envp)
{
	int sh_est;

	(void)ac;
	(void)av;
	//(void)envp;
	sh_var_start(envp);
	//ft_tabdel_n(sh_env_get(), "LS_COLORS");
	//ft_tabdel_i(sh_env_get(), 2);

	//sh_invar_init();
	//sh_hash_init();
	if (ac > 1)
		sh_est = (sh_file_run(av[1]));
	else
	{
		sh_est = (sh_term_run());
		sh_termconfig_reset();
	}
	//sh_cleanup();
	return (sh_est);
}

/*
 *
	ft_tabins(sh_var(), ft_tabrow_set(0, "NEW", "nvalue120", 0), 0);
	ft_tabput(sh_var(), "=");

	sh_bin_init(sh_bin_ptr());
	sh_bin_update(sh_bin(), sh_var_getval("PATH"));
	ft_printf("Bins Updated !!!\n");
	ft_printf("echo :: %s\n", sh_bin_getpath(sh_bin(), "echo"));

	sh_als_init();
	sh_als_add(sh_als(), "al1", "cd ");
	sh_als_add(sh_als(), "al2", "cd ; al2");
	sh_als_add(sh_als(), "al3", "al1 ; al2");


	sh_als_add(sh_als(), "AA", "BB");
	sh_als_add(sh_als(), "BB", "CC");
	sh_als_add(sh_als(), "CC", "AA");
 */
