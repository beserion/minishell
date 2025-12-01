#include "minishell.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

/*
** Simple parser that handles:
** - pipes (not inside quotes)
** - tokenization with single and double quotes
** - backslash escaping
** - redirections: <, >, >>, << (heredoc)
**
** Produces a linked list of t_cmd
*/

static int	is_special(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

/* allocate argv array from tokens */
static char **tokens_to_argv(char **tokens, int ntoks)
{
	char **argv = malloc((ntoks + 1) * sizeof(char *));
	int i;
	for (i = 0; i < ntoks; i++)
		argv[i] = tokens[i];
	argv[ntoks] = NULL;
	return (argv);
}

/* read heredoc content until delim, write to temp file and return filename */
static char *handle_heredoc(const char *delim)
{
	char template[] = "/tmp/minishell_heredoc_XXXXXX";
	int fd = mkstemp(template);
	if (fd == -1)
		return (NULL);
	FILE *f = fdopen(fd, "w+");
	if (!f)
	{	close(fd); return (NULL); }
	char *line = NULL;
	size_t len = 0;
	while (1)
	{
		printf("> ");
		ssize_t r = getline(&line, &len, stdin);
		if (r <= 0)
			break;
		/* strip newline */
		if (line[r-1] == '\n') line[r-1] = '\0';
		if (strcmp(line, delim) == 0)
			break;
		fprintf(f, "%s\n", line);
	}
	free(line);
	fflush(f);
	rewind(f);
	fclose(f);
	return (strdup(template));
}

/* tokenize a command string into tokens handling quotes and escapes */
static char **tokenize_cmd(const char *s, int *out_count)
{
	int cap = 16;
	char **tokens = malloc(cap * sizeof(char*));
	int count = 0;
	int i = 0;
	int n = strlen(s);
	while (i < n)
	{
		while (i < n && isspace((unsigned char)s[i])) i++;
		if (i >= n) break;
		if (count + 4 >= cap)
		{
			cap *= 2;
			tokens = realloc(tokens, cap * sizeof(char*));
		}
		if (s[i] == '\'' || s[i] == '"')
		{
			char q = s[i++];
			int bufcap = 64;
			char *buf = malloc(bufcap);
			int bi = 0;
			while (i < n && s[i] != q)
			{
				if (s[i] == '\\' && q == '"' && i+1 < n)
					buf[bi++] = s[++i];
				else
					buf[bi++] = s[i++];
				if (bi+1 >= bufcap) { bufcap *= 2; buf = realloc(buf, bufcap); }
			}
			buf[bi] = '\0';
			if (i < n && s[i] == q) i++;
			tokens[count++] = buf;
		}
		else if (s[i] == '<' || s[i] == '>')
		{
			int j = i;
			if (s[i+1] == s[i]) i += 2;
			else i++;
			int len = i - j;
			char *tok = malloc(len+1);
			strncpy(tok, s+j, len);
			tok[len] = '\0';
			tokens[count++] = tok;
		}
		else if (s[i] == '|')
		{
			char *tok = strdup("|");
			i++;
			tokens[count++] = tok;
		}
		else
		{
			int bufcap = 64;
			char *buf = malloc(bufcap);
			int bi = 0;
			while (i < n && !isspace((unsigned char)s[i]) && !is_special(s[i]))
			{
				if (s[i] == '\\' && i+1 < n)
					buf[bi++] = s[++i];
				else
					buf[bi++] = s[i++];
				if (bi+1 >= bufcap) { bufcap *= 2; buf = realloc(buf, bufcap); }
			}
			buf[bi] = '\0';
			tokens[count++] = buf;
		}
	}
	tokens[count] = NULL;
	*out_count = count;
	return (tokens);
}

/* Build command list from input line */
t_cmd *parse_line(const char *line)
{
	int ntoks = 0;
	char **toks = tokenize_cmd(line, &ntoks);
	if (!toks) return NULL;
	int i = 0;
	t_cmd *head = NULL;
	t_cmd *cur = NULL;
	char *infile = NULL;
	char *outfile = NULL;
	int append = 0;
	char *heredoc_tmp = NULL;
	char **argtokens = malloc(sizeof(char*) * (ntoks+1));
	int at = 0;
	while (i < ntoks)
	{
		char *tok = toks[i];
		if (strcmp(tok, "|") == 0)
		{
			/* finish current command */
			argtokens[at] = NULL;
			t_cmd *node = malloc(sizeof(t_cmd));
			node->argv = tokens_to_argv(argtokens, at);
			node->infile = infile;
			node->outfile = outfile;
			node->append = append;
			node->heredoc_tmp = heredoc_tmp;
			node->next = NULL;
			if (!head) head = node;
			else cur->next = node;
			cur = node;
			/* reset for next */
			infile = outfile = heredoc_tmp = NULL; append = 0;
			argtokens = malloc(sizeof(char*) * (ntoks+1));
			at = 0;
			i++;
			continue;
		}
		else if (strcmp(tok, "<") == 0)
		{
			/* next token is infile */
			i++;
			if (i < ntoks)
				infile = strdup(toks[i]);
			i++;
			continue;
		}
		else if (strcmp(tok, ">") == 0 || strcmp(tok, ">>") == 0)
		{
			append = (strcmp(tok, ">>") == 0);
			i++;
			if (i < ntoks)
				outfile = strdup(toks[i]);
			i++;
			continue;
		}
		else if (strcmp(tok, "<<") == 0)
		{
			i++;
			if (i < ntoks)
			{
				heredoc_tmp = handle_heredoc(toks[i]);
			}
			i++;
			continue;
		}
		else
		{
			argtokens[at++] = toks[i++];
			continue;
		}
	}
	/* final command */
	if (at > 0 || infile || outfile || heredoc_tmp)
	{
		argtokens[at] = NULL;
		t_cmd *node = malloc(sizeof(t_cmd));
		node->argv = tokens_to_argv(argtokens, at);
		node->infile = infile;
		node->outfile = outfile;
		node->append = append;
		node->heredoc_tmp = heredoc_tmp;
		node->next = NULL;
		if (!head) head = node;
		else cur->next = node;
	}
	/* free tokens array (tokens content moved or duplicated) */
	free(toks);
	return (head);
}
