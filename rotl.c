/** CODE to implement rotating the top value of the stack to the bottom*/

#include "monty.h"

/**
 * rotl - moves the top element of the stack to the last
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int top_n;

	(void)line_number;

	if (*stack != NULL)
	{
		top = *stack;
		top_n = top->n;

		/* Initiate rotation if the stack has at lease two elements */
		if (top->next != NULL)
		{
			while (top->next != NULL)
			{
				top->n = top->next->n;
				top = top->next;
			}
			top->n = top_n;
		}
		/* Else don't do anything */
	}
}
