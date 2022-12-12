#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"

#define BUF_SIZE 1024

/* Function declarations */
void print_prompt();
void read_command(char *command);
int execute_command(char *command);

/* Main function */
int main()
{
    /* Variables */
    char command[BUF_SIZE];

    /* Loop until the user enters "exit" */
    while (1)
    {
        print_prompt();
        read_command(command);

        /* Check if the user entered "exit" */
        if (strcmp(command, "exit") == 0)
        {
            break;
        }

        /* Execute the command */
        if (execute_command(command) != 0)
        {
            break;
        }
    }

    return 0;
}

/* Print the prompt */
void print_prompt()
{
    printf("$ ");
}

/* Read the command from the user */
void read_command(char *command)
{
    fgets(command, BUF_SIZE, stdin);
    command[strcspn(command, "\n")] = '\0';
}

/* Execute the command */
int execute_command(char *command)
{
    int status;

    /* Check if the command is empty */
    if (strlen(command) == 0)
    {
        return 0;
    }

    /* Execute the command */
    status = system(command);

    /* Check if the command was not found */
    if (status == 127)
    {
        printf("simple_shell: %s: command not found\n", command);
    }

    /* Return the command's exit status */
    return status;
}
