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
                        /* Free memory used by dynamically allocated variables*/
                        free(args);
                        free(line);

                        /* Close any open file streams*/
                        fclose(stdin);
                        fclose(stdout);
                        fclose(stderr);

                        /* Exit the shell with the specified exit status */
                        exit(*exstat);
                }
}

