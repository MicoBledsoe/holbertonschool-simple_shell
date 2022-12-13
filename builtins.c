#include "shell.h"
#include <stdio.h>

/**
 * builtin_exit - function that exits the shell
 * @buf: buffer
 * @args: the parsed arguments
 * @env: the environment
 * @exstat: exit status
 * Return: void
 */
void builtin_exit(char **buf, char **args, char **env, int *exstat)
{
    /* Free memory used by dynamically allocated variables */
    free(buf);
    free(args);
    free(env);

    /* Close any open file streams */
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);

    /* Exit the shell with the specified exit status */
    exit(*exstat);
}

