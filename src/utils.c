#include "minishell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t ms_strlen(const char *s)
{
	size_t i = 0;
	if (!s) return 0;
	while (s[i]) i++;
	return i;
}

char *ms_strdup(const char *s)
{
	if (!s) return NULL;
	size_t n = ms_strlen(s);
	char *p = malloc(n + 1);
	if (!p) return NULL;
	memcpy(p, s, n + 1);
	return p;
}

char *ms_strndup(const char *s, size_t n)
{
	size_t i = 0;
	while (i < n && s[i]) i++;
	char *p = malloc(i + 1);
	if (!p) return NULL;
	memcpy(p, s, i);
	p[i] = '\0';
	return p;
}

/* Free command list and unlink heredoc temp files */
#include <stdio.h>
void free_cmds(t_cmd *head)
{
	t_cmd *cur = head;
	while (cur)
	{
		t_cmd *next = cur->next;
		if (cur->argv)
		{
			for (int i = 0; cur->argv[i]; i++)
				free(cur->argv[i]);
			free(cur->argv);
		}
		if (cur->infile) free(cur->infile);
		if (cur->outfile) free(cur->outfile);
		if (cur->heredoc_tmp)
		{
			unlink(cur->heredoc_tmp);
			free(cur->heredoc_tmp);
		}
		free(cur);
		cur = next;
	}
}
