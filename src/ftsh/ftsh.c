#include "ftsh.h"
#include <fcntl.h>

t_sh	*g_sh;

int		sh_file_run(char *filename, char **envp)
{
	t_dstr	*dscript;
	t_sh	*sh;

	DF0
	ft_putendl(filename);
	if (!(dscript = ft_read_file(filename)))
		return (KO);
	sh_sh_init(&sh, envp, SH_MODE_SCR); // TODO: specify correct sh-mode
	return (sh_script_run(sh, dscript->str));
}

int		sh_script_run(t_sh *sh, char *script) // TODO: add sh as param (subsh ...)
{
	t_lex *lex;
	t_com_cmds *com_cmds;

	//ft_printf(C_CYN"\nScript:\n-------\n%s\n-------\n\n"T_END, script);
	if (!script)
		return (1);
	sh_lex_init(&lex, script);
	if (sh_lex_start(lex) == KO)
		return (KO);
	if (!lex->tlst)
		return (KO);
	if (!(com_cmds = sh_p_start(lex)))
		return (KO);
	//ft_printf(C_GRN"Parsed !!!\n"T_END);
	//sh->hd_key = lex->hd_key; // Replace by dastrdup
	//sh->hd_val = lex->hd_val; // Replace by dastrdup
	return (sh_e_com_cmds(sh, com_cmds));
}

int		sh_inter_read(char **line)
{
	//DF0
	//(void)line;
	//prompt_display();
	//signal(SIGINT, sighand_parent);
	//get_inline(line);
	*line = rl_start();
	return (0);
}

int		sh_term_run(char **envp)
{
	char	*line;
	int 	ret;

	DF0
	sh_sh_init(&g_sh, envp, SH_MODE_TER); // TODO: specify correct sh-mode
	rl_hist_init(RL_HIS_FILENAME);
	rl_hist_upload();
	rl_hist_print();
	line = "";
	ret = 0;
	while (ft_strcmp(line, "exit\n"))
	{
		sh_inter_read(&line);
		rl_hist_add(line);
		if (!ft_strncmp("exit", line, 4))
			return (0);
		ret = sh_script_run(g_sh, line);
//		ft_memdel((void**)line);
	}
	rl_hist_save(); // TODO: history_cleanup
	return (ret);
}

int		main(int ac, char **av, char **envp)
{
	int sh_est;

	if (ac > 1)
		sh_est = (sh_file_run(av[1], envp));
	else
	{
		sh_est = sh_term_run(envp);
		sh_termconfig_reset(&sh_sh()->term); // replace with sh_free
	}
	// TODO: sh_cleanup
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
