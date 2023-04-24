#include "shell1.h"

/**
 * REPL - REP loop
 * @input: isatty(STDIN_FILENO)
 **/
void REPL(int input)
{
	char *l = NULL;
	size_t c = 0;
	ssize_t a = 0;

	while (1)
	{
		if (input)
			write(STDOUT_FILENO, "$ ", 2);
		a = getline(&l, &c, stdin);
		if (a == EOF)
		{
			free(l);
			exit(0);
		}
		if (strcmp(l, "\n"))
		{
			execute_line(l);
			l = NULL;
		}
	}
}

/**
 * main - main function
 *
 * Return: 0 success, other otherwise
 **/
int main(void)
{

	REPL(isatty(STDIN_FILENO));

	return (0);
}
