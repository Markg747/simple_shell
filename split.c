#include "shell1.h"
#include <stddef.h>

/**
 * str_split - split a string into tokens by delimeter
 * @str: string
 * @del: delimeter
 * Return: array of strings of tokens
 **/
char **str_split(const char *str, const char del)
{
	char **s = NULL;
	int i = 0, j, w = 0;

	while (str[i] != '\0' && str[i] == del)
		i++;
	if (!str[i])
		return (NULL);
	i = 0;
	while (str[i])
	{
		j = i;
		if (str[i] != del)
		{
			s = _realloc(s, sizeof(char *) * w,
						 sizeof(char *) * (w + 1));
			s[w] = NULL;
			while (str[j] && str[j] != del)
			{
				s[w] = _realloc(s[w], (j - i), ((j - i) + 1));
				s[w][j - i] = str[j];
				j++;
			}
			s[w] = _realloc(s[w], (j - i), ((j - i) + 1));
			s[w][j - i] = '\0';
			i += (j - i);
			w++;
		}
		else
			i++;
	}
	s = _realloc(s, sizeof(char *) * w, sizeof(char *) * (w + 1));
	s[w] = NULL;

	return (s);
}

/**
 * free_arr - free the array
 * @arr: array
 **/
void free_arr(char **arr)
{
	int i = 0;

	while (arr[i])
		free(arr[i++]);
	free(arr);
}
