#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    char command[1024];

    // display prompt and wait for user input
    while (1) {
        printf("simple_shell> ");
        scanf("%s", command);

        // fork a new process
        int pid = fork();

        // check for errors in fork
        if (pid == -1) {
            perror("fork");
            exit(1);
        }

        // child process
        else if (pid == 0) {
            // execute the command
            int ret = execlp(command, command, NULL);

            // check for errors in execution
            if (ret == -1) {
                perror("execlp");
                exit(1);
            }
        }

        // parent process
        else {
            // wait for child process to finish
            wait(NULL);
        }
    }

    return 0;
}

