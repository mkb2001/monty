#include "monty.h"

FILE *file;
int FIFO = 0;

void print_errmsg_opcodefail(stack_t **pS, int number, char *opcode);

int main(int ac, char *argv[])
{
    char line[1024];

    int line_number = 1;

    stack_t *stack = NULL;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        lineReader(&stack, line, line_number);
        ++line_number;
    }
    fclose(file);
    free_stack_t(&stack);
    exit(EXIT_SUCCESS);
}





/**
 * get_opcode - gets the opcode from a line and formats it properly
 * @inst_line: the instruction line
 *
 * Return: pointer to the opcode
 */

char *get_opcode(char *inst_line)
{
    char *opcode;

    if (inst_line == NULL)
        return (NULL);

    /* Strip the newline character */
    inst_line[strlen(inst_line) - 1] = '\0';

    /* Get the opcode */
    opcode = strtok(inst_line, " ");
    return (opcode);
}

/**
 * is_empty - checks if an instruction line is empty
 * @inst_line: the instruction line
 *
 * Return: 1 if the instruction line is empty, 0 if not
 */

int is_empty(char *inst_line)
{
    if (is_newline(inst_line) == 1 || is_spaces(inst_line) == 1)
        return (1);
    return (0);
}

/**
 * is_spaces - checks if an instruction line is only spaces
 * @inst_line: the instruction line
 *
 * Return: 1 if the instruction line is empty, 0 if not
 */
int is_spaces(char *inst_line)
{
    if (inst_line != NULL)
    {
        while (*inst_line != '\n')
        {
            if (*inst_line != ' ')
                return (0);
            ++inst_line;
        }
    }
    return (1);
}
/**
 * is_newline - checks if an instruction line is empty
 * @inst_line: the instruction line
 *
 * Return: 1 if the instruction line is empty, 0 if not
 */
int is_newline(char *inst_line)
{
    if (inst_line != NULL)
        if (*inst_line == '\n')
            return (1);
    return (0);
}
