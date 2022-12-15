#include "shell.h"

/* Global array to hold environment variables */
extern char **environ;

/**
 * _getenv - gets environment for path
 * @name: const char
 * Detailed Description of BLOCK: contains a C function called _getenv(), which is used to retrieve the value of an environment variable. 
 The function takes a single argument, name, which is a string containing the name of the environment variable to retrieve. 
 The function also uses the environ global array,which holds the list of environment variables and their values.
The function starts by declaring two local variables: i and pathvalue. The i variable will be used as a loop counter to iterate through
the list of environment variables stored in the environ array. The pathvalue variable will be used to store the value of the environment variable specified by name.
The function then enters a for loop, which will continue to execute as long as the environ array at the current position 
(specified by i) is not NULL. Inside the loop, the function compares the first 4 characters of the current environment variable with name using the _strncmp() function.
If the two strings match, the function uses the _strdup() function to duplicate the value of the environment variable (which starts at the 5th character of the environ array at 
the current position),and stores the result in pathvalue.
Once the for loop ends, the function returns the value of pathvalue, which will be the value of the environment variable specified by name, or NULL if the variable was not found.
 * Return: NULL
 */

char *_getenv(char *name)
{
	int i;
	char *pathvalue;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, 4) == 0)
		{
			pathvalue = _strdup(&environ[i][5]);
			return (pathvalue);
		}
	}
	return (NULL);
}
