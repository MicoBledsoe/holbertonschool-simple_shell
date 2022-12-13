#include "shell.h"
#include <stdio.h>

/**
 * builtfunc - function that implements the exit builtin
 * @buf: buffer
 * @args: the parsed arguments
 * @env: the environment
 * @exstat: exit status
 * Detailed Description: This code is a function that implements the exit builtin command for a simple shell program. The exit builtin is a command that is built into the shell and can be used to terminate the shell process. When the exit builtin is used, the shell will clean up any dynamically allocated memory, close any open file streams, and then exit with the specified exit status.

The builtfunc function takes four parameters: buf, args, env, and exstat. buf is a pointer to a buffer that is used to store input from the user, args is an array of strings containing the arguments that were passed to the builtin command, env is a pointer to the environment variables for the current process, and exstat is a pointer to the exit status for the shell.

Inside the function, there is a check to see if the first argument (i.e. the command name) is "exit". If it is, then the function frees the memory that was allocated for the buf, args, and env variables using the free function. It also closes any open file streams using the fclose function, and then exits the shell using the exit function and the specified exit status.

If the first argument is not "exit", then the function does nothing and simply returns void. This allows the calling code to check for other builtin commands and handle them accordingly.
 * Return: void
 */
void builtfunc(char **buf, char **args, char **env, int *exstat)
{
        /* Check if the first argument is "exit" */
        if (_strcmp(args[0], "exit") == 0)
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
}
