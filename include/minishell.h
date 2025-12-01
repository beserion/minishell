#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>

int     is_builtin(char *cmd);
int     run_builtin(char **argv);


typedef struct s_cmd
{
	char **argv;
	char *infile;
	char *outfile;
	int append;
	char *heredoc_tmp;
	struct s_cmd *next;
} t_cmd;

typedef struct s_token
{
        char **parts;
}       t_token;

size_t	ms_strlen(const char *s);
char	*ms_strdup(const char *s);
char	*ms_strndup(const char *s, size_t n);
t_cmd	*parse_line(const char *line);
int		exec_pipeline(t_cmd *head);
void	free_cmds(t_cmd *head);

#endif
