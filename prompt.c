#include <stdio.h>
#include <stdlib.h>

FILE *database = NULL; // input file

int main(int ac, char *av[])
{
    /* assuming the user obeyed syntax and gave input-file as first argument*/  
    char *input = av[1];

    /* Initializing input/database file */
    database = fopen(input, "r");
    if(database == NULL)
    {
        fprintf(stderr, "Something went wrong with reading the database/input file. Does it exist?\n");
        exit(EXIT_FAILURE);
    }

    printf("INFO: database file %s loaded.\n", input);

    /* Crucial part printing line after line */
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while((read = getline(&line, &len, database)) != -1)
    {
        printf("INFO: Retrieved line of length %zu :\n", read);
        printf("%s \n", line);
        char confirm; // wait for user keystroke to proceed
        scanf("%c", &confirm);
        // no need to do anything with "confirm"
    }

    /* tidy up */
    free(line);
    fclose(database);
    exit(EXIT_SUCCESS);
}
