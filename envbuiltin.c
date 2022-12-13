#include "shell.h"

/**
* envbuiltin - function that prints current environment
* @environ: double pointer to list of env variables
* Detailed Description: This code is a function that prints the current environment variables to the standard output. It does this by iterating over an array of strings called environ, which is a global variable defined in the standard C library. This array contains the environment variables that are set for the current process.

The function has a single parameter, environ, which is a double pointer to the environ array. It then uses a while loop to iterate over the elements in the array, and for each element it prints the string using the _puts and _putchar functions. These functions are custom functions that are defined elsewhere in the code, but they likely have similar functionality to the standard puts and putchar functions.

The envbuiltin function returns void, meaning it does not return a value. Instead, it simply prints the environment variables to the standard output and then exits.
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
