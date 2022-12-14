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
        char *tokens[1024];
        char *token;

        const char *delim = " ";
        token = strtok(str, delim);

        if (!token)
                return (-1);

        /* Limit the number of tokens to 1024 */
        while (token != NULL && count < 1024)
        {
                tokens[count++] = token;
                token = strtok(NULL, delim);
        }

        /* Check if the array was completely filled */
        if (count == 1024)
        {
                fprintf(stderr, "Too many tokens in input string!\n");
                return (-1);
        }

        print_string(tokens[count - 1]);
        print_string("\n");

        /* Set the last element of the array to NULL */
        tokens[count] = NULL;

        /* Free the memory allocated to the tokens array */
        free(tokens);

}
