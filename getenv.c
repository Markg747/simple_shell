#include "shell1.h"

/**
 * _getenv - get environment value of name
 * @name: name of environment variable
 *
 * Return: value of env
 **/

char *_getenv(const char *name)
{
	int i = 0, j;

	if (!name)
		return (NULL);

	while (environ[i])
	{
		j = 0;
		while (name[j] && name[j] == environ[i][j])
			j++;
		if (!name[j] && environ[i][j] == '=')
		{
			return (environ[i] + (j + 1));
		}

		i++;
	}

	return (NULL);
}
