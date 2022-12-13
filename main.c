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
/* This line above declares a variable len of type size_t and initializes it to 1024. The size_t type is an unsigned integer type that is large enough to hold the size of any object in bytes. The len variable will be used later in the code to specify the maximum length of the input buffer when reading input from the user.
The argc and argv variables are the arguments passed to the main() function. The argc variable is an integer that specifies the number of command line arguments passed to the program. The argv variable is an array of strings containing the command line arguments. These arguments are not used in this code block, so they are cast to void to suppress compiler warnings.*/

	/* buffer is input, or command entered/// This line declares and initializes four variables: buffer, prompt, array, and token. The buffer variable is a character pointer (char *) that will be used to store the input entered by the user. It is initialized to NULL, which indicates that the pointer currently points to no valid memory location.
The prompt variable is also a char * and will be used to store the prompt string that is displayed to the user when the shell is running in interactive mode. It is not initialized in this code block, so its value is undefined.
The array variable is an array of char * values that will be used to store the individual tokens (or words) of the input entered by the user. It is declared with a size of 1024, which means it can hold up to 1024 char * values.
The token variable is a char * that will be used to store the result of the strtok() function when parsing the input entered by the user into individual tokens. It is not initialized in this code block, so its value is undefined.*/
	char *buffer = NULL, *prompt, *array[1024], *token;

/* cpid is child process // this whole code block below all the way to (void)argc, and (void)argv : This code block declares and initializes several variables that will be used later in the program.
The cpid variable is declared as pid_t and will be used to store the process ID of the child process that is created when a command entered by the user is executed. The pid_t type is a signed integer type used to represent process IDs.The status variable is an int that will be used to store the status of the child process when it terminates. This information can be used to determine whether the child process terminated successfully or not.
The exstat variable is an int that will be used to store the exit status of the shell program. It is initialized to 0, which indicates that the program has not yet exited.
The pPath variable is a char * that will be used to store the value of the PATH environment variable, which specifies the directories where the shell should search for commands.
The pathtoken variable is a char * that will be used to store the result of the strtok() function when parsing the PATH variable into individual directory paths.
The pathname variable is a char * that will be used to store the full pathname of a command when searching for it in the directories specified by the PATH variable.
The i variable is an int that will be used as a loop counter in various parts of the program.
The argc and argv variables are cast to void to suppress compiler warnings, since they are not used in this code block.*/
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

/* This block of code below sets all elements of the array variable to NULL, and then enters an infinite loop. Inside the loop, it checks whether the program is running in interactive mode (where input is entered directly from the keyboard rather than from a file or another source) by calling the isatty() function. If the program is running in interactive mode, it prints a prompt string to the screen using the _puts() function. This prompts the user to enter a command. The loop will continue to run and print the prompt until the program is exited. */
/* accounting for junk values // what this cod block is DOING: This code block is defining an infinite loop that will be used to repeatedly prompt the user for input and execute commands entered by the user.
The first line of the code block is a for loop that iterates over the elements of the array variable, which was declared and initialized earlier in the program. For each element of the array, the NULL value is assigned to it, which indicates that the element is not currently pointing to any valid memory location.
The next line is the start of the while loop, which is an infinite loop that will continue to execute until the program is exited. Inside the loop, the code will check if the program is running in interactive mode (where input is entered directly from the keyboard rather than from a file or another source), and if so, it will print a prompt string to the screen using the _puts() function. This prompts the user to enter a command, which will be read by the program and executed. The loop will continue to run and print the prompt until the program is exited.*/
	for (i = 0; i < 1024; i++)
		array[i] = NULL;
	while (1)
	{
/* print prompt every time only in interactive mode // WHAT THIS CODE BLOCK IS DOING: This code block checks whether the program is running in interactive mode (where input is entered directly from the keyboard rather than from a file or another source), and if so, it prints a prompt string to the screen using the _puts() function.
The isatty() function is called with the STDIN_FILENO constant as its argument. This function returns a non-zero value if its argument is a file descriptor associated with a terminal device, and 0 if it is not. In this case, the isatty() function will return a non-zero value if the program is running in interactive mode, and 0 if it is not.
If the isatty() function returns a non-zero value (indicating that the program is running in interactive mode), the prompt variable is assigned the string "($) ", which is the prompt string to be printed to the screen. Then, the _puts() function is called with the prompt variable as its argument, which writes the prompt string to the standard output (stdout).
If the isatty() function returns 0 (indicating that the program is not running in interactive mode), then the code in this block is not executed and the prompt string is not printed to the screen. */
		if (isatty(STDIN_FILENO) == 1)
		{
			prompt = "($) ";
			_puts(prompt);
		}

/* if getline reads line from stream and is unsuccessful, break // WHAT THIS CODE BLOCK IS DOING: This code block reads a line of input from the standard input (stdin) and stores it in the buffer variable.
The getline() function is called with the following arguments:
The address of the buffer variable, which is a pointer to a string where the input will be stored.
The address of the len variable, which is a pointer to a size_t type that holds the length of the input buffer.
The stdin file descriptor, which specifies that the input will be read from the standard input.
The getline() function reads a line of text from the standard input, up to the next newline character or the end of the input, and stores it in the buffer variable. If the input is successfully read, the function returns the number of characters that were read, not including the null terminator character. If an error occurs or the end of the input is reached, the function returns -1 and sets the errno variable to indicate the error that occurred.
In this code block, the return value of getline() is checked against -1. If the return value is -1 (indicating that an error occurred or the end of the input was reached), the break statement is executed, which exits the while loop. This causes the program to stop prompting the user for input and stop executing commands.
If the return value of getline() is not -1 (indicating that a line of input was successfully read), the code in this block is not executed and the program continues to the next step in the while loop. */
		if (getline(&buffer, &len, stdin) == -1)
		{
			break;
		}
/* set value of token equal to a string of broken down tokens // WHAT THIS CODE BLOCK IS DOING: this line of code uses the strtok() function to split the buffer string on the newline character, and sets the token variable to the
first token that is found. This is useful for parsing the input string into separate tokens that can be processed by the rest of the program.*/
		token = strtok(buffer, "\n");
		
/* set address of array of tokens equal to a duplicated string */
/* allocates memory for new string using strdup */
/* This code block uses the strtok() function to split the buffer string on the space character (' '), and stores each resulting token in the array variable. The strtok() function is called once with the buffer string as its first argument, and the space character as its second argument. This tells strtok() to search the buffer string for the first occurrence of a space character, and to return a pointer to the token that was found (up to the first space character, if one exists).
The token variable is set to the pointer returned by strtok(), which points to the first token in the buffer string (up to the first space character, if one exists). A local variable i is declared and initialized to 0, and will be used as an index into the array variable to store the tokens that are found.
Next, the code enters a while loop that continues as long as token is not NULL (i.e., as long as strtok() returns a non-NULL pointer). Inside the loop, the _strdup() function is called with the token string as its argument. This creates a new string that is a copy of the token string, and returns a pointer to the new string. The array[i] element is set to the pointer returned by _strdup(), which stores the new string in the array variable.
The strtok() function is then called again, this time with the NULL value as its first argument. This tells strtok() to continue tokenizing the string from the previous call, using the same delimiter characters (in this case, the space character). The token variable is then set to the pointer returned by strtok(), which points to the next token in the buffer string (up to the next space character, if one exists */
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
/* This code block is a conditional statement that checks if the command entered by the user is "env" (using the _strcmp() function to compare the entered command 
with the "env" string). If the entered command is "env", the envbuiltin() function is called with the environ global variable as its argument. This function prints the current environment variables to stdout. Then, the buffer and array variables are freed to release their memory, and the loop continues to the next iteration. If the entered command is not "env", the code block is skipped and the program continues to the next step in the loop. */
		if (_strcmp(buffer, "env") == 0)
		{
			envbuiltin(environ);
			free(buffer);
			double_free(array);
			continue;
		}
/* This block of code below is responsible for executing the command entered by the user. If the input is not a built-in command (such as "env" or "exit"), the code will attempt to execute the input as a command in the shell by searching the directories specified in the PATH environment variable for a valid, executable file with the same name as the command entered by the user. If a valid file is found, the code forks a child process and uses the execve() function to execute the command. Otherwise, the code sets the pathname variable to the command entered by the user and attempts to execute the command from the current working directory. The code continues to prompt for input and execute commands until it is exited. */
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
