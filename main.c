#include "monty.h"

FILE *file;
int FIFO = 0;



int main(int ac, char *argv[])
{

    char line[1024];
    /* char *line = NULL; */
    /* size_t n = 0; */
    int line_number = 1;
    stack_t *stack = NULL;

    /* Check the number of arguments passed to main */
    if (ac != 2)
        print_errmsg_argfail();

    /* Open the file for reading */
    file = fopen(argv[1], "r");
    if (file == NULL)
        print_errmsg_openfail(argv);

    /* Get instruction line by line */
    /* while (getline(&line, &n, file) != -1) */
    while (fgets(line, sizeof(line), file) != NULL)
    {
        lineReader(&stack, line, line_number);
        ++line_number;
    }
    fclose(file);
    free_stack_t(&stack);
    /* free(line); */
    exit(EXIT_SUCCESS);
}
