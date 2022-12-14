# 0x17. C - Simple Shell Project

## Definition:

A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

## Description: 

This program is a simple shell in the C programming language. It takes user input, parses it, and then executes the corresponding command. The program includes several custom functions, such as _putchar and _puts, which are used to write characters and strings to the standard output, respectively. The main function is the entry point of the program and is where the majority of the shell's functionality is implemented. The program reads a line of input from the user, parses it into tokens, and then checks if the input matches any built-in commands (e.g. env and exit). If it does, the corresponding built-in function is called. Otherwise, the program attempts to execute the input as a command by searching the directories listed in the PATH environment variable for a matching executable file. If one is found, it is executed with the provided arguments. If not, an error message is printed. The program runs in a loop, allowing the user to enter multiple commands.

## Instructions:

All code is compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

### List of allowed functions and system calls:
 | FUNCTIONS | MAN PAGE |
 | ---------- | --------|
| access | (man 2 access)|
| chdir | (man 2 chdir) |
| close | (man 2 close) |
| closedir | (man 3 closedir) |
| execve | (man 2 execve) |
| exit | (man 3 exit) |
| exit | (man 2 _exit) |
| fflush | (man 3 fflush) |
| fork | (man 2 fork) |
| free | (man 3 free) |
| getcwd | (man 3 getcwd) |
| getline | (man 3 getline) |
| getpid | (man 2 getpid) |
| isatty | (man 3 isatty) |
| kill | (man 2 kill) |
| malloc | (man 3 malloc) |
| open | (man 2 open) |
| opendir | (man 3 opendir) |
| perror | (man 3 perror) |
| read | (man 2 read) |
| readdir | (man 3 readdir) |
| signal | (man 2 signal) |
| stat (__xstat) | (man 2 stat) |
| lstat (__lxstat) | (man 2 lstat) |
| fstat (__fxstat) | (man 2 fstat) |
| strtok | (man 3 strtok) |
| wait | (man 2 wait) |
| waitpid | (man 2 waitpid) |
| wait3 | (man 2 wait3) |
| wait4 | (man 2 wait4) |
| write | (man 2 write) |

## Collaborators: 

Mico Bledsoe; github - (@MicoBledsoe)

Ricardo Corona; github -(@LW068)
