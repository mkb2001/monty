/** CODE to implement dividing the two values at the top of the stack */

#include "monty.h"

/**
 * _div - subtracts the top two elements of the stack
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2 = NULL;
	int n1, n2;

	if (*stack != NULL)
	{
		top1 = *stack;
		top2 = (*stack)->next;
	}
	if (top2 == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack_t(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	else
	{
		n1 = top1->n;
		n2 = top2->n;
		if (n1 == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free_stack_t(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		else
		{
			top2->n = n2 / n1;
			pop(stack, line_number);
		}
	}
}
