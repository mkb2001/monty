/** CODE to implement multiplying the two values at the top of the stack */

#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2 = NULL;
	int n1, n2;

	if (*stack != NULL)
	{
		top1 = *stack;
		top2 = (*stack)->next;
	}
	if (top2 != NULL)
	{
		n1 = top1->n;
		n2 = top2->n;
		top2->n = n2 * n1;
		pop(stack, line_number);
	}
	if (top2 == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack_t(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
