#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024

/* Libraries */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <limits.h>

/* Global array to hold environment variables */
extern char **environ;

/* MACRO to define environment */
#define _GNU_SOURCE

/* Environment function */
void envbuiltin(char **environ);

/* Get environment (path) function */
char *_getenv(char *name);

/* Helper functions for strings */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
char *string_nconcat(char *s1, char *s2, unsigned int n);
char *_strstr(char *haystack, char *needle);
int m_getline();

/* EXTRAS */
int print_string(char *str);
int parse_line(char *str);
void double_free(char **array);
void builtfunc(char **args, int *exstat, char *line);

/* Free double pointer function */
void double_free(char **array);

/* Helper functions for writing */
int _putchar(char c);
void _puts(char *s);

#endif
