#include "shell.h"
#include <stdio.h>

/**
 * builtfunc - function that implements the exit builtin
 * @buf: buffer
 * @args: the parsed arguments
 * @env: the environment
 * @exstat: exit status
 * Return: void
 */

void builtfunc(char **args, int *exstat, char *line)
{
	if (_strcmp(args[0], "exit") == 0)
		{
			free(args);
			free(line);
			exit(*exstat);
		}
}
