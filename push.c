#include "monty.h"

/**
* push - adds a value to the top of the stack
* @stack: the stack data structure to push to
* @line_number: the line number of the instruction in the MBCF
*
* Return: nothing
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_block = NULL;
	char *val;

	int n;

	if (stack != NULL)
	{
		/* Attempt to get the value */
		val = strtok(NULL, " ");
		if (val == NULL || (stoi(val) == 0 && (*val != '0' && *val != '-')))
		{

			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			free_stack_t(stack);
			fclose(file);
			/* free(line); */
			exit(EXIT_FAILURE);
		}
	}

	/* If value was gotten, create a new block of memory */
	new_block = (stack_t *)malloc(sizeof(stack_t));
	if (new_block == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* Assign values to the members of the new block */
	n = atoi(val);
	new_block->n = n;
	new_block->prev = NULL;
	new_block->next = NULL;

	/* For empty stack */
	if (*stack == NULL) /* Same for queues and stacks */
		*stack = new_block;
	/* For a non-empty stack */
	else
	{
		if (FIFO == 0) /* Stack data structure */
			push_to_stack(&new_block, stack);
		else
			enqueue(&new_block, stack);
	}
}

