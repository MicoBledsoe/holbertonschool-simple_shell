#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * _getenv - gets environment for path
 * @name: const char
 * Return: NULL
 */

char *_getenv(char *name)
{
	int i;
	char *pathvalue;

	for (i = 0; nvrmt[i] != NULL; i++)
	{
		if (_strncmp(nvrmt[i], name, 4) == 0)
		{
			pathvalue = _strdup(&nvrmt[i][5]);
			return (pathvalue);
		}
	}
	return (NULL);
}
