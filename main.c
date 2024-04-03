#include "monty.h"

int main(int argc, char *argv[])
{
    char *cont;
    FILE *file;
    size_t size = 0;
    size_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");

    if (!file)
    {
        fprintf(stderr , "Error: Can not open the file");
        exit(EXIT_FAILURE);
    }

    while(read_line > 0){
        cont = NULL;
        read_line = getline(&cont, &size, file);
        counter++;
        if (read_line > 0)
        {
            execute(cont, &stack, counter, file);
//            printf("I was started");
        }
        free(cont);
    }
    fclose(file);
    return (0);
}