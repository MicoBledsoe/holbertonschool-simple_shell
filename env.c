#include "shell.h"

/**
* envbuiltin - function that prints current environment
* @environ: double pointer to list of env variables
* Detailed Description of code BLOCK: contains a C function called envbuiltin(), which is used to print the current environment variables. The function takes a single argument, environ, which is a double pointer to the list of environment variables. The function also uses the _puts() and _putchar() functions to print the environment variables to the screen.
The function starts by declaring a local variable i and initializing it to 0. This variable will be used as a loop counter to iterate through the list of environment variables stored in environ. The function then enters a while loop, which will continue to execute as long as environ at the current position (specified by i) is not NULL. Inside the loop, the function uses _puts() to print the current environment variable to the screen, followed by a newline character using _putchar(). The i variable is then incremented to move to the next environment variable.
Once the while loop ends, the function returns 0 to indicate success.
* Return: 0 on success
*/

void envbuiltin(char **environ)
{
	int i;

	i = 0;
	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}
