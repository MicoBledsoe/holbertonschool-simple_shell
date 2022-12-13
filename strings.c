#include "shell.h"
#include <stdlib.h> /* standard library */
#include <stdio.h>
#include <string.h>

/**
* _strlen - returns the length of string
* @s: the string being passed
* Description: 0x05-pointers_arrays_strings/2-strlen.c
* Detailed Description of code BLOCK: calculates the length of a string. The function is called _strlen and it takes a single argument, a pointer to a character (char *s), which is the string whose length we want to calculate.
The function starts by declaring a local variable count and initializing it to 0. This variable will be used to keep track of the number of characters in the string.
Next, the function enters a while loop, which will continue to execute as long as the character at the current position in the string (specified by the count variable) is not the null character ('\0'). Inside the loop, the count variable is incremented to move to the next character in the string.
Once the while loop ends, the function returns the final value of the count variable, which will be the length of the string.
* Return: the length of the string
**/

int _strlen(char *s)
{
int count = 0;

while (s[count] != '\0')
{
count++;
}
return (count);
}
/**
* *_strcpy - function that copies string pointed to by src, includes the '\0'
* @dest: char type string
* @src: char type string
* Description: 0x05-pointers_arrays_strings/9-strcpy.c
* Detailed Description of BLOCK: copies the contents of one string to another. The function is called _strcpy and it takes two arguments: a pointer to a character (char *dest), which is the destination string where the copied characters will be stored, and a pointer to a character (char *src), which is the source string that will be copied.
The function starts by declaring a local variable i and initializing it to 0. This variable will be used as a loop counter to keep track of the current position in the source string.
Next, the function enters a for loop, which will continue to execute as long as the character at the current position in the source string (specified by the i variable) is not the null character ('\0'). Inside the loop, the character at the current position in the source string is copied to the corresponding position in the destination string, and the i variable is incremented to move to the next character in the source string.
Once the for loop ends, the function sets the null character ('\0') at the end of the destination string, to mark the end of the copied string. Finally, the function returns a pointer to the destination string.
* Return: Pointer to `dest`
**/

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
* _strcat - function that concatenates two strings
* @dest: the string being concatenated
* @src: the string being concatenated
* Description: 0x06-pointers_arrays_strings/0-strcat.c
* Detailed Description of BLOCK: concatenates (joins) two strings together. The function is called _strcat and it takes two arguments: a pointer to a character (char *dest), which is the destination string where the concatenated string will be stored, and a pointer to a character (char *src), which is the source string that will be concatenated to the end of the destination string.
The function starts by declaring three local variables: i, s, and n. The s variable is initialized by looping through the source string until the null character ('\0') is found, and it will be used to store the length of the source string. The n variable is initialized by looping through the destination string until the null character ('\0') is found, and it will be used to store the length of the destination string. Finally, the i variable is initialized to 0 and will be used as a loop counter.
Next, the function enters a for loop, which will continue to execute as long as the i variable is less than or equal to the length of the source string (stored in the s variable). Inside the loop, the character at the current position in the source string is copied to the corresponding position in the destination string (which is n + i characters from the start of the string, where n is the length of the destination string and i is the current position in the source string), and the i variable is incremented to move to the next character in the source string.
Once the for loop ends, the function returns a pointer to the destination string. This string will contain the original destination string, followed by the concatenated source string.
* Return: dest
**/

char *_strcat(char *dest, char *src)
{
	int i;
	int s;
	int n;

	for (s = 0; src[s] != '\0'; s++)
	{
		;
	}
	for (n = 0; dest[n] != '\0'; n++)
	{
		;
	}
	for (i = 0; i <= s ; i++)
	{
		*(dest + (n + i)) = src[i];
	}
	return (dest);
}

/**
* _strcmp - comparing two strings
* @s1: string
* @s2: string
* Description: 0x06-pointers_arrays_strings/3-strcmp.c
* Detailed Description of BLOCK: compares two strings and returns 0 if they are the same, or a non-zero value if they are different. The function is called _strcmp and it takes two arguments: a pointer to a character (char *s1), which is the first string to compare, and a pointer to a character (char *s2), which is the second string to compare.
The function starts by declaring a local variable a and initializing it to 0. This variable will be used as a loop counter to keep track of the current position in the two strings.
Next, the function enters a for loop, which will continue to execute as long as the character at the current position in either of the two strings (specified by the a variable) is not the null character ('\0'). Inside the loop, the function compares the characters at the current position in the two strings, and if they are different, the function returns the difference between the two characters (using the s1[a] - s2[a] expression). This difference will be a non-zero value if the two strings are different, or 0 if the two strings are the same up to the current position.
Once the for loop ends, the function returns 0, indicating that the two strings are the same. This will happen if the two strings have the same length and their characters are the same at each position. If the two strings have different lengths, the for loop will end when the null character ('\0') is reached in one of the strings, and the difference between the two strings will have been returned by the if statement inside the loop.
* Return: 0
**/

int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != '\0' || s2[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
	}
	return (0);
}

/**
* _strdup - Duplicate a string using malloc
* @str: string to duplicate
* Description: 0x0B-malloc_free/1-strdup.c
* Return: Pointer to a the new duped string
**/

char *_strdup(char *str)
{
	char *a;
	int i, c;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	a = malloc(i * sizeof(*a) + 1);
	if (a == NULL)
		return (NULL);

	for (c = 0; c < i; c++)
		a[c] = str[c];
	a[c] = '\0';

	return (a);
}

/** _stncmp - compares two strings
 * @s1: character
 * @s2: character
 * @n: integer
 * Detailed Description of BLOCK: contains a function called _strncmp that takes in three arguments: two strings and an integer. The function compares the two strings character by character, starting from the first character in each string, until it reaches the end of one of the strings or until it has compared n characters, whichever comes first.
The function starts by declaring a local variable a and initializing it to 0. This variable will be used as a loop counter to keep track of the current position in the strings.
Next, the function enters a for loop, which will continue to execute as long as the character at the current position in the first string (specified by the a variable) is not the null character ('\0') or the character at the current position in the second string is not the null character ('\0'). Inside the loop, the function first checks if the a variable is equal to n. If it is, the function breaks out of the loop. Otherwise, the function compares the character at the current position in the first string to the character at the current position in the second string. If the two characters are not equal, the function returns the difference between the two characters (i.e., s1[a] - s2[a]).
Once the for loop ends, the function returns 0, indicating that the two strings are equal up to the nth character.
 * Return: comparison or 0
 */
int _strncmp(char *s1, char *s2, int n)
{
        int a;

        for (a = 0; s1[a] != '\0' || s2[a] != '\0'; a++)
        {
		if (a == n)
			break;
                if (s1[a] != s2[a])
                        return (s1[a] - s2[a]);
        }
        return (0);
}

/**
 * string_nconcat - concatenate two strings
 * @s1: character
 * @s2: character
 * @n: unsigned integer
 * Return: new string, or NULL
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *newstring;
	int s1len = 0;
	unsigned int i;
	unsigned int j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[s1len] != '\0')
		s1len++;

	newstring = malloc(sizeof(char) * (s1len + n + 1));

	if (newstring == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		newstring[i] = s1[i];
	for (j = 0; j < n && s2[j] != '\0'; i++, j++)
		newstring[i] = s2[j];
	newstring[i] = ('\0');
	return (newstring);
}


/**
 * _strstr - locate a substring
 * description: locate a substring
 * @haystack: character
 * @needle: character
 * Detailed Description of BLOCK: contains a function called _strstr that takes in two strings as arguments: a haystack and a needle. The function searches the haystack string for the needle string and returns a pointer to the first occurrence of the needle string in the haystack string, or NULL if the needle string is not found in the haystack string.
The function starts by declaring two local variables: i and j. The i variable will be used to keep track of the current position in the haystack string, and the j variable will be used to keep track of the current position in the needle string.
Next, the function enters an outer for loop, which will continue to execute as long as the character at the current position in the haystack string (specified by the i variable) is not the null character ('\0'). Inside the outer for loop, the function enters an inner for loop, which will continue to execute as long as the character at the current position in the needle string (specified by the j variable) is not the null character ('\0'). Inside the inner for loop, the function compares the character at the current position in the haystack string (specified by the i and j variables) to the character at the current position in the needle string. If the two characters are not equal, the function breaks out of the inner for loop.
Once the inner for loop ends, the function checks if the j variable is equal to the null character ('\0') in the needle string. If it is, the function has found the needle string in the haystack string, so it returns a pointer to the start of the needle string in the haystack string. Otherwise, the function continues to the next iteration of the outer for loop.
Once the outer for loop ends, the function returns NULL, indicating that the needle string was not found in the haystack string.
 * Return: NULL
 */

char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (needle[j] == '\0')
			return (haystack + i);
	}
	return (NULL);
}
