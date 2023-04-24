#include "shell1.h"
/**
 * _ls - list files
 * @dir: directory
 * @op_a: option
 * @op_l: option
 **/
void _ls(const char *dir, int op_a, int op_l)
{

	struct dirent *d;
	DIR *dh = opendir(dir);

	if (!dh)
	{
		if (errno == ENOENT)

		{

			perror("Directory doesn't exist");
		}
		else
		{

			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	while ((d = readdir(dh)) != NULL)
	{
		if (!op_a && d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if (op_l)
			printf("\n");
	}
	if (!op_l)
		printf("\n");
}

/**
 * _env - print environment
 * @av: array of arguments
 * Return: 1 or 2
 **/
int _env(char **av __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		if (write(STDOUT_FILENO, environ[i], strlen(environ[i])) == -1)
		{
			perror("env");
			return (2);
		}
		write(STDOUT_FILENO, "\n", 1);

		i++;
	}
	return (1);
}

/**
 * _cd - change directory
 * @av: array of arguments
 * Return: 1 or 2
 **/
int _cd(char **av)
{
	if (av[1] == NULL)
	{
		if (chdir(getenv("HOME")) == -1)
		{
			perror("cd");
			return (2);
		}
	}
	else
	{
		if (chdir(av[1]) == -1)
		{
			perror("cd");
			return (2);
		}
	}
	return (1);
}

/**
 * fexit - exit shell
 * @av: array of arguments
 *
 * Return: exist or 2
 **/
int fexit(char **av)
{
	int status;

	if (av[1] == NULL)
	{
		free_arr(av);
		exit(0);
	}

	else
	{
		status = atoi(av[1]);
		free_arr(av);
		exit(status);
	}
	return (2);
}

