#include "shell1.h"

/**
* eror - print error
* @name: name of component producing the error
* @err: string of error
*
**/
void eror(char *name, char *err)
{
	write(STDOUT_FILENO, "hsh: ", 5);
	write(STDOUT_FILENO, name, strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, err, strlen(err));
}

/**
* exec_func - execute
* @av: array of arguments
* Return: 1 or 2
*
**/
int exec_func(char **av)
{
	builtin builtins[] = {{"cd", _cd}, {"exit", fexit},
	{"env", _env}, {NULL, NULL}};
	int i = 0;

	while (builtins[i].s)
	{
		if (strcmp(builtins[i].s, av[0]) == 0)
			return (builtins[i].f(av));
		i++;
	}

	return (0);
}

/**
* run_fork - fork and run program with parameters
*
* @av: array of strings of program and it's pramaters
*
* Return: return value of child process
**/
int run_fork(char **av)
{

	pid_t my_pid, child;
	int wstatus;

	child = fork();

	if (child == -1)
		perror("hsh");

	if (child == 0)
	{
		my_pid = execve(av[0], av, environ);
		if (my_pid == -1)
			exit(1);
	}

	else
		wait(&wstatus);

	return (WEXITSTATUS(wstatus));
}

/**
* execute_line - execute line of commands
* @line: line
**/
void execute_line(char *line)
{
	char **av, *p;
	char **lines;
	int i = 0;

	line[strlen(line) - 1] = '\0';
	lines = str_split(line, ';');
	free(line);
	while (lines[i])
	{
		av = str_split(lines[i], ' ');
		i++;
		if (av != NULL)
		{
			if (!strcmp(av[0], "exit"))
				free_arr(lines);

			if (!exec_func(av))
			{
				p = strdup(av[0]);

				if (_path(av[0]) || _match(&av[0]))
				{
					run_fork(av);
				}
				else
					eror(av[0], "not found\n");
				free(p);
			}
		free_arr(av);
		}
	}
	free_arr(lines);
}
