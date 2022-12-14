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
    int count = 0, bufsize = BUFFER_SIZE;
    char *tokens[1024], *token, *temp;
    const char *delim = " ";

    temp = strdup(str);
    if (!temp)
        return (-1);

    token = strtok(temp, delim);
    if (!token)
        return (-1);

    while (token != NULL)
    {
        tokens[count++] = token;
        if (count == bufsize)
            return (-1);
        token = strtok(NULL, delim);
    }

    print_string(tokens[count - 1]);
    print_string("\n");
    tokens[count] = NULL;

    free(temp);

    return (count);
}
