#include "shell.h"
#include <stdlib.h> /* standard library */
#include <stdio.h>
#include <string.h>

/**
* _strlen - returns the length of string
* @s: the string being passed
* Description: 0x05-pointers_arrays_strings/2-strlen.c
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

/**
 *
 *
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
