#ifndef SHELL1_H
#define SHELL1_H


extern char **environ;

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>
#include <wait.h>
#include <stddef.h>
#include <errno.h>
#include <dirent.h>



/**
 * struct builtin - the shell builtins
 * @s: name of builtins
 * @f: what the builtins do (or function)
 **/


typedef struct builtin
{
	char *s;
	int (*f)(char **av);

} builtin;

int _env(char **av);
int _cd(char **av);
int fexit(char **av);


char **str_split(const char *str, const char del);
void free_arr(char **tow);



char *_getenv(const char *name);
char *_match(char **s);
int _path(char *s);

void execute_line(char *line);





void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);





#endif
