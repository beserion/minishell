#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

/* forward */
t_cmd *parse_line(const char *line);
int exec_pipeline(t_cmd *head);
void free_cmds(t_cmd *head);

/* completion: simple filename completion using rl_filename_completion_function */
char **myshell_completion(const char *text, int start, int end)
{
	(void)end;
	/* if completing first word (command), also fall back to filename completion */
	if (start == 0)
	{
		/* Could implement PATH-based command completion here.
		   For now, use filename completion as a simple fallback. */
		return rl_completion_matches(text, rl_filename_completion_function);
	}
	return rl_completion_matches(text, rl_filename_completion_function);
}

static void	sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;

	rl_attempted_completion_function = myshell_completion;
	rl_bind_key('\t', rl_complete);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	using_history();
	char *line;
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break;
		if (*line)
			add_history(line);
		t_cmd *cmds = parse_line(line);
		if (cmds)
		{
			exec_pipeline(cmds);
			free_cmds(cmds);
		}
		free(line);
	}
	return (0);
}
