#include "shell.h"

/**
* envbuiltin - function that prints current environment
* @environ: double pointer to list of env variables
* Return: 0 on success
*/

void envbuiltin(char **environ)
{
	int i;

	i = 0;
	while (environ[i] != '\0')
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}
