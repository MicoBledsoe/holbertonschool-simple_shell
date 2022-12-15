#include "shell.h"

/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Deetailed Description: This code defines a function called _putchar that takes a character as an argument and writes it to the standard output (stdout). The function is implemented as follows:
The function STARTS by declaring its argument c of type char, which is the character to be written to stdout.
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
The function STARTS by declaring its argument s of type char *, which is a pointer to the string to be written to stdout.
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

/* cpid is child process // this whole code block BELOW all the way to (void)argc, and (void)argv : This code block declares and initializes several variables that will be used later in the program.
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
The next line is the start of the while loop, which is an infinite loop that will continue to execute until the program is exited. Inside the loop, the code will check if the program is running in interactive mode (where input is entered directly from the keyboard rather than from a file or another source), and if so, it will print a prompt string to the screen using the _puts() function.
This prompts the user to enter a command, which will be read by the program and executed. The loop will continue to run and print the prompt until the program is exited.*/
	for (i = 0; i < 1024; i++)
		array[i] = NULL;
	while (1) /* This is the infinite loop */
	{
/* print prompt every time only in interactive mode // WHAT THIS CODE BLOCK IS DOING: This code block checks whether the program is running in interactive mode (where input is entered directly from the keyboard rather than from a file or another source), and if so, it prints a prompt string to the screen using the _puts() function.
The isatty() function is called with the STDIN_FILENO constant as its argument. This function returns a non-zero value if its argument is a file descriptor associated with a terminal device, and 0 if it is not. In this case, the isatty() function will return a non-zero value if the program is running in interactive mode, and 0 if it is not.
If the isatty() function returns a non-zero value (indicating that the program is running in interactive mode), the prompt variable is assigned the string "($) ", which is the prompt string to be printed to the screen. Then, the _puts() function is called with the prompt variable as its argument, which writes the prompt string to the standard output (stdout).
If the isatty() function returns 0 (indicating that the program is not running in interactive mode), then the code in this block is not executed and the prompt string is not printed to the screen. */
		if (isatty(STDIN_FILENO) == 1) /* 1 means it's running in intercative mode */
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

/* The code starts by calling the "_strcmp" function with the "buffer" and "env" strings as its arguments. The "_strcmp" function is a custom implementation of the standard "strcmp" function, which compares two strings and returns 0 if they are equal. In this case, if "_strcmp" returns 0, it means that the user entered the "env" command.

If "_strcmp" returns 0, the code calls the "envbuiltin" function with the "environ" variable as its argument. The "envbuiltin" function is a custom function that appears to be used for printing the environment variables to the standard output.

Next, the code frees the memory allocated to the "buffer" variable using the "free" function, and then calls the "double_free" function with the "array" variable as its argument. The "double_free" function is a custom function that appears to be used for freeing the memory allocated to the "array" variable and any other variables that it points to.

Finally, the code uses the "continue" statement to skip the rest of the code in the current iteration of the loop and move on to the next iteration. This ensures that the program does not try to execute any other commands if the user entered the "env" command. */
		if (_strcmp(buffer, "env") == 0)
		{
			envbuiltin(environ);
			free(buffer);
			double_free(array);
			continue;
		}
		
/* This block of code below is responsible for executing the command entered by the user. If the input is not a built-in command (such as "env" or "exit"), the code will attempt to execute the input as a command in the shell by searching the directories specified in the PATH environment variable for a valid, executable file with the same name as the command entered by the user. If a valid file is found, the code forks a child process and uses the execve() function to execute the command. Otherwise, the code sets the pathname variable to the command entered by the user and attempts to execute the command from the current working directory. The code continues to prompt for input and execute commands until it is exited. */
/* if the input is a command typed "exit", the exit func will be called */
		
/* checks if the user entered the "exit" command, which is a built-in shell command that terminates the program.

The code starts by calling the "_strcmp" function with the "buffer" and "exit" strings as its arguments. The "_strcmp" function is a custom implementation of the standard "strcmp" function, which compares two strings and returns 0 if they are equal. In this case, if "_strcmp" returns 0, it means that the user entered the "exit" command.

If "_strcmp" returns 0, the code frees the memory allocated to the "buffer" variable using the "free" function, and then calls the "double_free" function with the "array" variable as its argument. The "double_free" function is a custom function that appears to be used for freeing the memory allocated to the "array" variable and any other variables that it points to.

The code then calls the "exit" function with the "exstat" variable as its argument. The "exit" function is a standard C function that terminates the program and returns the specified exit status to the calling process. In this case, the "exstat" variable specifies the exit status that the program should return.

Finally, the code uses the "continue" statement to skip the rest of the code in the current iteration of the loop and move on to the next iteration. This ensures that the program does not try to execute any other commands if the user entered the "exit" command. */
		if (_strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			double_free(array);
			exit(exstat);
			continue;
		}
		pPath = _getenv("PATH"); /* FROM LINE 177 - 207 this CODE BLOCK IS DOING: The code starts by calling the "getenv" function with the string "PATH" as its argument. This function is a standard C function that gets the value of the specified environment variable. In this case, the "PATH" environment variable is a list of directories that the program should search for the specified command. The value of "PATH" is returned by "getenv" and stored in the "pPath" variable.
Next, the code calls the "strtok" function with "pPath" as its first argument and the string ":" as its second argument. The "strtok" function is a standard C function that splits a string into tokens using a specified delimiter. In this case, the delimiter is a colon (:), so the function will split the "pPath" string on colons and return the first token (i.e. the first directory path in the "PATH" variable). This token is stored in the "pathtoken" variable.
The code then enters a loop that continues until the "pathtoken" variable is NULL, indicating that there are no more tokens to process. Inside the loop, the code first allocates memory for the "pathname" variable using the "malloc" function. This variable will be used to store the full path to the command that the user entered.
The code then checks if the user-entered command contains a forward slash by calling the "strstr" function with "array[0]" (the first token of the user input) as its first argument and the string "/" as its second argument. If the "strstr" function returns NULL, it means that the user-entered command does not contain a forward slash, and the code assumes that it is the name of an executable file located in one of the directories in the "PATH" variable. In this case, the code concatenates the current directory path from "pathtoken" with the name of the command, and stores the result in "pathname".
If the user-entered command does contain a forward slash, the code assumes that it is the full path to the command, and it simply copies the command into "pathname" without appending any directory paths. The loop is then terminated by calling the "break" statement.
After the "pathname" variable has been populated, the code calls the "access" function with "pathname" and the value "X_OK" as its arguments. The "access" function is a standard C function that checks the accessibility of a file. In this case, the "X_OK" value indicates that the code is checking whether the file specified by "pathname" is executable by the current user. If "access" returns 0, it means that the file is executable, and the loop is terminated by calling the "break" statement.
If "access" does not return 0, it means that the file is not executable, and the code moves on to the next directory path in the "PATH" variable by calling "strtok" with the argument "NULL". This advances the token pointer to the next token in the "PATH" variable, and the "pathtoken" variable is updated with the new directory path. The code then frees the memory allocated to "pathname" and sets the variable to NULL to prepare for the next iteration of the loop.*/
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
			pathname = NULL; /* Line 187 */
		}
		if (pathtoken == NULL) /* From Line 209 - 265 this CODE BLOCK IS DOING : It follows a block of code that searches the directories specified by the "PATH" environment variable for the command that the user entered.

The code starts by checking if the "pathtoken" variable is NULL, indicating that no executable file was found in any of the directories in the "PATH" variable. If "pathtoken" is NULL, the code assumes that the user-entered command is the full path to the command, and it copies the command into the "pathname" variable using the "strdup" function.

Next, the code frees the memory allocated to the "pPath" variable, which is no longer needed. This is done to avoid memory leaks and ensure that the program does not use up too much memory.

The code then checks if the "token" variable is NULL, which indicates that the user entered a command that the program recognizes as a built-in shell command. If "token" is NULL, the code continues to the next section of code, which is responsible for executing the user-entered command.

The code starts by calling the "fork" function, which creates a new child process that is a duplicate of the current parent process. The return value of "fork" is stored in the "cpid" variable.

If "fork" returns -1, it indicates that an error occurred while creating the child process, and the code calls the "perror" function to print an error message to the standard error output. The function then returns 1, indicating that the program encountered an error.

If "fork" returns 0, it indicates that the child process was successfully created, and the code calls the "execve" function to execute the user-entered command. The "execve" function takes three arguments: the path to the command to execute, the command line arguments passed to the command, and the environment in which the command should be executed. In this case, the path to the command is stored in the "pathname" variable, the command line arguments are stored in the "array" variable, and the environment is passed as the "environ" variable.

If "execve" returns -1, it indicates that an error occurred while executing the command, and the code calls the "perror" function to print an error message to the standard error output. The code then frees the memory allocated to the "pathname", "array[0]", and "buffer" variables and exits the program with the exit status -1.

If "execve" does not return -1, it indicates that the command was executed successfully. In this case, the child process continues to run the command, while the parent process enters a "wait" loop, which waits for a signal to be received or the child process to exit. When the child process terminates, the parent process continues to the next line of code, which calls the "double_free" function with the "array" variable as its argument, and then frees the memory allocated to the "pathname" and "buffer" variables.

Finally, after all of the commands have been executed, the function returns 0, indicating that the program ran successfully. */
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
