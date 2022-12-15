#include "shell.h"

/**
 * double_free - free double pointer
 * @array: some double pointer array
 * Detailed Description: This code defines the double_free() function, which frees the memory allocated for a double pointer array. 
 The function takes a double pointer array as an argument and iterates over each element of the array, 
 freeing the memory associated with each element. This is useful for freeing the memory allocated for an array of strings, 
 such as the array variable used in the main() function of the shell. The function does not return a value. */
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
