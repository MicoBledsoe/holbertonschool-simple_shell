#include "shell.h"

/** This code is a function that takes a string as input and returns the number of tokens (i.e. words separated by spaces) in the string. It does this by using the strtok function, which is a standard C function for splitting a string into tokens based on a delimiter. In this case, the delimiter is a space, so the function splits the string into individual words. It then stores these words in an array of char pointers called tokens, and returns the number of tokens that were found.
The function also has a helper function, print_string, which simply writes the input string to the standard output (i.e. the terminal). This is used to print the last token in the tokens array, followed by a newline character. */

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
 * detailed explanation: This is the print_string function, which is a helper function used by the parse_line function.
 This function takes a char pointer called str as input, which points to the string that is to be printed.
 * return (write(STDOUT_FILENO, str, strlen(str)));: This is the return statement for the function. It writes the input string, str, to the standard output (i.e. the terminal) using the write function, which is a standard C 
 function for writing data to a file descriptor. The write function takes three arguments: the file descriptor to write to, the string to write, and the length of the string. In this case, the file descriptor is STDOUT_FILENO, which is a macro that represents the standard output file descriptor. The length of the string is obtained using the strlen function, which is a standard C function for finding the length of a string. The write function returns the number of bytes that were written, so this value is also returned by the print_string function.
 * Return: number of tokens which is count
 */

/* The function first declares and initializes local variables for the buffer size and the count of tokens. 
It then declares an array of char pointers called tokens, which will be used to store the individual words in the input string.

The function then uses the strtok function to split the input string into tokens based on the space character as a delimiter. 
It stores the first token in the token variable, and then checks if the token is NULL. If the token is NULL, the function returns -1 
to indicate that the string was empty or did not contain any tokens.

If the token is not NULL, the function enters a while loop that continues to execute as long as the token variable is not NULL. 
Inside the while loop, the function stores the current token in the tokens array and increments the count of tokens. 
It also checks if the count of tokens has reached the buffer size, and if so, it returns -1 to indicate that the function has failed. 
After storing the current token in the tokens array, the function sets the token variable to the next token in the input string using the strtok function.

Once the while loop ends, the function returns the count of tokens that were found in the input string.
This value indicates the number of words that were separated by spaces in the input string.


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

	
	
/* This is the last block of code in the parse_line function, which is the main function for splitting a string into tokens and returning the number of tokens that were found. Here is an explanation of each line in this block of code:

/* printf("%s\n", tokens[count - 1]);: This is a commented-out line that would print the last token in the tokens array, followed by a newline character. This line is commented out because the next line of code does the same thing using the print_string function.

 
 BLOCK STARTS HERE: print_string(tokens[count - 1]);: This line uses the print_string function to print the last token in the tokens array. The print_string function simply writes the input string to the standard output, so this line prints the last token to the terminal.

print_string("\n");: This line uses the print_string function to print a newline character to the standard output. This adds a newline after the last token that was printed in the previous line.

tokens[count] = NULL;: This line sets the last element in the tokens array to NULL. This is useful because NULL is a special value that indicates the end of an array of char pointers.

return (count);: This is the final line of the function, which returns the number of tokens that were found. This value is stored in the count variable, which is incremented for each token that is found in the input string
/* return number of tokens */

/*	printf("%s\n", tokens[count - 1]);*/
	print_string(tokens[count - 1]);
	print_string("\n");
	tokens[count] = NULL;
	return (count);
}
