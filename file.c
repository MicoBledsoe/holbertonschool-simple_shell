#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

int main(int argc, char **argv) {
  // Set up some variables
  size_t len = 1024;
  char *buffer = NULL, *prompt, *command, *token;
  pid_t cpid;
  int status, exstat = 0;

  // Loop forever (until an EOF or error is encountered)
  while (1) {
    // Print the prompt, if we are in interactive mode
    if (isatty(STDIN_FILENO) == 1) {
      prompt = "($) ";
      puts(prompt);
    }

    // Read a line from the input
    if (getline(&buffer, &len, stdin) == -1) {
      break;
    }

    // Tokenize the input into separate commands
    token = strtok(buffer, "\n");
    command = strtok(buffer, " ");

    // If the command is "env", print the environment
    if (strcmp(buffer, "env") == 0) {
      for (char **env = environ; *env; env++) {
        printf("%s\n", *env);
      }
      continue;
    }

    // If the command is not found, print an error message
    if (access(command, F_OK) == -1) {
      fprintf(stderr, "%s: command not found\n", command);
      continue;
    }

    // Create a child process to execute the command
cpid = fork();

// If the fork failed, print an error message and exit
if (cpid == -1) {
  perror("fork");
  exit(1);
}

// If we are in the child process, execute the command
if (cpid == 0) {
  if (execvp(command, argv) == -1) {
    perror("execvp");
    exit(1);
  }
}
