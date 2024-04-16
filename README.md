# Holberton School Simple Shell Project

## Introduction

This repository contains the Simple Shell project, an educational initiative designed to teach students how to build a Unix shell from scratch. This command-line interpreter provides a user interface for Unix-like operating systems, blending interactive commands with a scripting environment.

## Definition

A Unix shell is an interactive command-line interpreter that provides a user interface for Unix-like operating systems. It also serves as a powerful scripting language used by the operating system to control the execution of the system using shell scripts.

## Description

The Simple Shell program processes user commands, parses them, and executes the appropriate systems calls. This shell supports basic features like executing commands found in the PATH environment variable, handling errors, and providing a functional and interactive command-line interface.

- **_putchar**: Writes a character to stdout.
- **_puts**: Outputs a string to stdout.
- **main**: Acts as the entry point for the shell, managing input parsing and command execution.

## Functionality

The shell operates in a loop, reading user input, parsing it into tokens, and executing the corresponding commands. It includes custom implementations of standard functions to handle I/O operations internally:

- Parses user input to identify and execute built-in commands such as `env` and `exit`.
- Searches for executable files in the directories listed in the PATH environment variable.
- Executes external programs and scripts passed as input.

## Usage Instructions

Compile the shell with the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

./hsh

### Part 4: List of Functions and System Calls
```markdown
## List of Allowed Functions and System Calls

- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `execve` (man 2 execve)
- `exit` (man 3 exit), `_exit` (man 2 _exit)
- `fork` (man 2 fork)
- `getline` (man 3 getline)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `perror` (man 3 perror)
- `stat`, `lstat`, `fstat` (__xstat, __lxstat, __fxstat) (man 2 stat)
- `wait`, `waitpid` (man 2 wait, waitpid)
- `write` (man 2 write)

## Collaborators

- **Mico Bledsoe** - [GitHub Profile](https://github.com/MicoBledsoe)
- **Ricardo Corona** - [GitHub Profile](https://github.com/LW068)

