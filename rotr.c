/** CODE to implement rotating the bottom value of the stack to the top*/

#include "monty.h"

/**
 * rotr - moves the bottom element of the stack to the top
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int bottom_n;

	(void)line_number;

	if (*stack != NULL)
	{
		top = *stack;
		while (top->next != NULL)
			top = top->next;
		bottom_n = top->n;
		while (top->prev != NULL)
		{
			top->n = top->prev->n;
			top = top->prev;
		}
		top->n = bottom_n;
	}
}
