/** CODE to implement printing the ASCII value of the top of the stack */

#include "monty.h"

/**
 * pchar - prints the Ascii value of the top of the stack
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack_t(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n;
	if (val >= 0 && val <= 127)
		printf("%c\n", val);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack_t(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
