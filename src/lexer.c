#include "minishell.h"
#include <stdlib.h>


static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static size_t	word_count(const char *s)
{
	size_t i;
	size_t count;

	if (!s) return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_whitespace(s[i])) i++;
		if (s[i])
		{
			count++;
			while (s[i] && !is_whitespace(s[i])) i++;
		}
	}
	return (count);
}

static char *word_dup(const char *s, size_t start, size_t len)
{
	char *ret = malloc(len + 1);
	if (!ret) return (NULL);
	for (size_t i = 0; i < len; i++) ret[i] = s[start + i];
	ret[len] = '\0';
	return (ret);
}

char **ms_split_whitespace(char *s)
{
	size_t count;
	char **arr;
	size_t i;
	size_t j;
	size_t start;

	if (!s) return (NULL);
	count = word_count(s);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr) return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < count)
	{
		while (s[i] && is_whitespace(s[i])) i++;
		start = i;
		while (s[i] && !is_whitespace(s[i])) i++;
		arr[j] = word_dup(s, start, i - start);
		if (!arr[j])
		{
			while (j > 0) { free(arr[j - 1]); j--; }
			free(arr);
			return (NULL);
		}
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

t_token *lexer(char *line)
{
	t_token *tok;

	if (!line) return (NULL);
	tok = malloc(sizeof(t_token));
	if (!tok) return (NULL);
	tok->parts = ms_split_whitespace(line);
	return (tok);
}

void token_clear(t_token *tok)
{
	size_t i;

	if (!tok) return;
	if (!tok->parts) { free(tok); return; }
	i = 0;
	while (tok->parts[i]) { free(tok->parts[i]); i++; }
	free(tok->parts);
	free(tok);
}
