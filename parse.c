#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * print_string - prints string
 * @str: char
 * Return: string
 */

int print_string(char *str)
{
	return (write(STDOUT_FILENO, str, strlen(str)));
}
/**
 * parse_line - tokenizing each line that is read
 * @str: line
 * Return: number of tokens which is count
 */

int parse_line(char *str)
{
	int bufsize = BUFFER_SIZE, count = 0;
/* allocating buffer size for amount of tokens */
	char *tokens[1024];
	char *token;

/* declaring the space as a delimiter */
	const char *delim = " ";
/* declaring a pointer to the first token */
	token = strtok(str, delim);

	if (!token)
		return (-1);
/* walk through other tokens */
	while (token != NULL)
	{
/* token is equal to the count of tokens */
		tokens[count++] = token;
/* if buffer size is reached, function has failed */
		if (count == bufsize)
			return (-1);
/* token is equal to the last token which is NULL */
		token = strtok(NULL, delim);
	}
/* return number of tokens */
/*	printf("%s\n", tokens[count - 1]);*/
	print_string(tokens[count - 1]);
	print_string("\n");
	tokens[count] = NULL;
	return (count);
}
