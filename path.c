#include "shell1.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * _path - is path?
 * @path: path
 *
 * Return: 1 (not absolute) 0 (absolute)
 **/
int _path(char *path)
{
	if (strlen(path) > 3)
	{
		if ((path[0] == '.' && path[1] == '/') || path[0] == '/' ||
			(path[0] == '.' && path[1] == '.' && path[2] == '/'))
			return (1);
	}

	return (0);
}

/**
 * make_path - make path to file from directory and file
 * @path: path to directory
 * @file: file
 * Return: New Path
 **/
char *make_path(char *path, char *file)
{
	char *n;

	if (path == NULL || file == NULL)
		return (NULL);

	n = malloc(sizeof(char) *
		(strlen(path) + strlen(file) + 2));
	if (!n)
		return (NULL);

	strcpy(n, path);
	n[strlen(path)] = '/';
	n[strlen(path) + 1] = '\0';
	strcat(n, file);

	return (n);
}

/**
 * _match - find directory insid PATH
 * that file resides in if any
 * @exec: executable name
 * Return: full path of executable or NULL if it's not found
 **/
char *_match(char **exec)
{
	char **array, *p, *path;
	int i = 0;
	struct stat st;

	path = getenv("PATH");
	if (strlen(path) == 0)
		return (NULL);

	array = str_split(path, ':');
	if (!array)
		return (NULL);

	while (array[i] != NULL)
	{
		p = make_path(array[i], *exec);
		if (stat(p, &st) == 0)
		{
			free(*exec);
			*exec = p;
			free_arr(array);
			return (p);
		}

		free(p);
		i++;
	}
	free_arr(array);
	return (NULL);
}
