#include "shell.h"

/**
* envbuiltin - function that prints current environment
* @nvrmt: double pointer to list of env variables
* Return: 0 on success
*/

void envbuiltin(char **nvrmt)
{
	int i;

	i = 0;
	while (nvrmt[i] != '\0')
	{
		_puts(nvrmt[i]);
		_putchar('\n');
		i++;
	}
}
