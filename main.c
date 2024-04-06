#include "monty.h"

FILE *file;
int FIFO = 0;

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
 * lineReader - interpretes a line to determine its operation
 * @stack: the stack data structure
 * @line: the instruction line to interprete
 * @line_number: the number of the instruction in the file
 *
 * Return: 1 if successfully interpreted, 0 if instruction not found
 */
int lineReader(stack_t **stack, char *line, int line_number)
{
    char *opcode;

    if (is_empty(line) != 0)
        return (0);

    opcode = get_opcode(line);

    /* Handle the nop opcode */
    if (strcmp(opcode, "nop") == 0)
        return (0);

    /* Handle comment */
    if (strncmp(opcode, "#", 1) == 0)
        return (0);

    /* Validate the opcode and call function handler */
    if (ref_func(opcode) == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);
        free_stack_t((stack_t **) &stack);
        fclose(file);
        /* free(line); */
        exit(EXIT_FAILURE);
    }
    else
        ref_func(opcode)((stack_t **) &stack, line_number);
    return (0);
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
