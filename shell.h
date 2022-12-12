#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024

#include <stdlib.h> /* standard library */
#include <stdio.h> /* standard input/output */
#include <string.h> /* handles strings */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/* global array to hold environment variables */
extern char **environ;

/* MACRO to define environ */
#define _GNU_SOURCE

/* main function */
int main(int argc, char **argv);

/* environment function */
void envbuiltin(char **environ);

/* get environment (path) function */
char *_getenv(char *name);

/* helper funcs for strings */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
char *string_nconcat(char *s1, char *s2, unsigned int n);
char *_strstr(char *haystack, char *needle);

/* free double pointer function */
void double_free(char **array);

/* helper funcs for writing */
int _putchar(char c);
void _puts(char *s);

#endif /* SHELL_H */
