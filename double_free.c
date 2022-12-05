#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * double_free - free double pointer
 * @array: some double pointer array
 * Return: void
 */
void double_free(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
}
