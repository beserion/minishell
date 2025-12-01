#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

/* forward prototypes for builtin to avoid implicit decls if header missing */
int is_builtin(char *cmd);
int run_builtin(char **argv);

static void	child_restore_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

/* apply redirections for a command before exec */
static int	apply_redirs(t_cmd *c)
{
	int fd;
	if (c->infile)
	{
		fd = open(c->infile, O_RDONLY);
		if (fd == -1) { fprintf(stderr, "minishell: %s: %s\n", c->infile, strerror(errno)); return (1); }
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if (c->heredoc_tmp)
	{
		fd = open(c->heredoc_tmp, O_RDONLY);
		if (fd == -1) { fprintf(stderr, "minishell: heredoc temp: %s\n", strerror(errno)); return (1); }
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if (c->outfile)
	{
		int flags = O_WRONLY | O_CREAT | (c->append ? O_APPEND : O_TRUNC);
		fd = open(c->outfile, flags, 0644);
		if (fd == -1) { fprintf(stderr, "minishell: %s: %s\n", c->outfile, strerror(errno)); return (1); }
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (0);
}

/* execute a pipeline of commands */
int	exec_pipeline(t_cmd *head)
{
	int prev_fd = -1;
	int pipefd[2];
	pid_t pid;
	t_cmd *c = head;
	int status = 0;

	/* If single builtin with no redirections, execute in parent process so
	   that state changes (like cd) affect the shell. */
	if (head && head->next == NULL && head->argv && is_builtin(head->argv[0])
		&& !head->infile && !head->outfile && !head->heredoc_tmp)
	{
		return (run_builtin(head->argv));
	}

	while (c)
	{
		if (c->next)
		{
			if (pipe(pipefd) == -1) { perror("pipe"); return (1); }
		}
		pid = fork();
		if (pid == -1) { perror("fork"); return (1); }
		if (pid == 0)
		{
			/* child */
			child_restore_signals();
			if (prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}
			if (c->next)
			{
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[0]);
				close(pipefd[1]);
			}
			/* redirections */
			if (apply_redirs(c)) exit(1);
			/* builtin handling in child: run and exit */
			if (is_builtin(c->argv[0]))
			{
				int r = run_builtin(c->argv);
				exit(r);
			}
			/* external */
			execvp(c->argv[0], c->argv);
			fprintf(stderr, "minishell: %s: %s\n", c->argv[0], strerror(errno));
			exit(127);
		}
		else
		{
			/* parent */
			if (prev_fd != -1) close(prev_fd);
			if (c->next)
			{
				close(pipefd[1]);
				prev_fd = pipefd[0];
			}
			c = c->next;
		}
	}
	/* wait for children */
	while (wait(&status) > 0)
		;
	return (0);
}
