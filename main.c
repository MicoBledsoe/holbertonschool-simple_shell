#include "shell.h"

/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Deetailed Description: This code defines a function called _putchar that takes a character as an argument and writes it to the standard output (stdout). The function is implemented as follows:
The function starts by declaring its argument c of type char, which is the character to be written to stdout.
The write function is called with the following arguments:
1: the file descriptor for stdout
&c: the address of the c character
1: the number of characters to write (in this case, only one character)
The return value of write is returned by _putchar, which indicates whether the write was successful. If the write was successful, the function returns 1. Otherwise, it returns -1 and sets the errno variable to indicate the error that occurred.
In short, this function is a simple wrapper around the write function that writes a single character to stdout. It is used later in the code to write characters one at a time, rather than writing strings all at once.
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _puts - custom function prints a string
* @s: pointer to the string
* Detailed Description: This code defines a function called _puts that takes a string as an argument and writes it to the standard output (stdout). The function is implemented as follows:
The function starts by declaring its argument s of type char *, which is a pointer to the string to be written to stdout.
A local variable i of type int is declared and initialized to 0. This variable will be used as an index into the s string to access individual characters.
The function enters a while loop that continues until the null terminator character (\0) is reached in the s string.
Inside the loop, the _putchar function is called with the i-th character of the s string as its argument. This writes the character to stdout.
The i variable is incremented by 1 to move on to the next character in the s string.
The loop repeats until the null terminator character is reached, at which point the function exits.
In short, this function is a simple implementation of the puts function that writes a string to stdout. It does this by calling the _putchar function to write each character of the s string one at a time, until the end of the string is reached. This is useful for printing prompts and other messages to the user in the command interpreter.
* Return: void
*/

void _puts(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
* main - function that is a Unix command interpreter
* @argc: integer
* @argv: character
* Return: void
*/

int main(int argc, char **argv)
{
	size_t len = 1024;
/* buffer is input, or command entered */
	char *buffer = NULL, *prompt, *array[1024], *token;
/* cpid is child process */
	pid_t cpid;
/* status is used in wait() as a variable that stores the status of cpid */
	int status;
/* exstat is a variable like EXIT_SUCCESS */
	int exstat = 0;
	char *pPath;
	char *pathtoken;
	char *pathname;
	int i;
/*	char *names[526]; */
	(void)argc, (void)argv;

/* accounting for junk values */
	for (i = 0; i < 1024; i++)
		array[i] = NULL;
	while (1)
	{
/* print prompt every time only in interactive mode */
		if (isatty(STDIN_FILENO) == 1)
		{
			prompt = "($) ";
			_puts(prompt);
		}

/* if getline reads line from stream and is unsuccessful, break */
		if (getline(&buffer, &len, stdin) == -1)
		{
			break;
		}
/* set value of token equal to a string of broken down tokens */
		token = strtok(buffer, "\n");
/* set address of array of tokens equal to a duplicated string */
/* allocates memory for new string using strdup */
		token = strtok(buffer, " ");
		i = 0;
		while (token)
		{
			array[i] = _strdup(token);
                        token = strtok(NULL, " ");
			i++;
		}
/* if the input is a command typed "env", the environment will be printed */
/* (if buffer is "env", return our envbuiltin function) */
		if (_strcmp(buffer, "env") == 0)
		{
			envbuiltin(environ);
			free(buffer);
			double_free(array);
			continue;
		}
/* if the input is a command typed "exit", the exit func will be called */
		if (_strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			double_free(array);
			exit(exstat);
			continue;
		}
		pPath = _getenv("PATH");

		pathtoken = strtok(pPath, ":");
		while (pathtoken)
		{
			pathname = malloc(sizeof(char) * 526);
			if (!pathname)
				perror("Error");
			pathname[0] = '\0';
			if (!_strstr(array[0], "/"))
			{
				_strcat(pathname, pathtoken);
				_strcat(pathname, "/");
				_strcat(pathname, array[0]);
			}
			else
			{
				free(pathname);
				pathname = _strdup(array[0]);
				break;
			}
			if (access(pathname, X_OK) == 0)
				break;
			pathtoken = strtok(NULL, ":");
			free(pathname);
			pathname = NULL;
		}
		if (pathtoken == NULL)
			pathname = _strdup(array[0]);
		free(pPath);
/* if not any of the above statements, fork child process */
		if (!token)
		{
/* set child equal to the forked parent */
			cpid = fork();
/* if there is an error forking, return "Error:" */
			if (cpid == -1)
			{
				perror("Error");
				return (1);
			}
/* if successful, run execve so the parent can duplicate into a child process */
			if (cpid == 0)
			{
/* execve(path, argv, env) */
/* if it is executed and an error occurs, return -1 */
				if (execve(pathname, array, environ) == -1)
					perror("Error");
				free(pathname);
				free(array[0]);
				free(buffer);
				exit(-1);
			}
			else
			{
/* wait for parent process to a signal is received or the child exits */
/* after child process terminates, parent continues its next execution */
				wait(&status);
			}
                        double_free(array);
		}
		free(pathname);
		free(buffer);
	}
/* return zero upon success */
	return (0);
}
