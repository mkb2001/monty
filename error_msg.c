#include "monty.h"
/**
* print_errmsg_opcodefail - prints an error message for failed push
* @stack: the stack data structure
* @line_number: the line number of the instruction
* @opcode: the invalid instruction code
*
* Return: nothing
*/

void print_errmsg_opcodefail(stack_t **stack, int line_number, char *opcode)
{
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack_t(stack);
	fclose(file);
	/* free(line); */
	exit(EXIT_FAILURE);
}
/**
* print_errmsg_argfail - prints an error message for wrong arguments
*
* Return: nothing
*/

void print_errmsg_argfail(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
* print_errmsg_openfail - prints an error message for a failed open operation
* @argv: list of arguments passed to main
*
* Return: nothing
*/
void print_errmsg_openfail(char *argv[])
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
}
