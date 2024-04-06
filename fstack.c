#include "monty.h"

/**
* free_stack_t - frees a doubly linked list representation of a stack
* @stack: the stack data structure
*
* return: nothing
*/

void free_stack_t(stack_t **stack)
{
	stack_t *temp;

	if (stack != NULL && *stack != NULL)
	{
		while ((*stack)->next != NULL)
		{
			temp = *stack;
			*stack = temp->next;
			free(temp);
		}
		free(*stack);
	}
}
