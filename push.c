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


/**
 * push_to_stack - pushes a new block up to a stack
 * @new_block: the new block to push to the top of the stack
 * @stack: the stack to push the new block to
 *
 * Return: nothing
 */

void push_to_stack(stack_t **new_block, stack_t **stack)
{
    (*new_block)->next = *stack;
    (*stack)->prev = *new_block;
    *stack = *new_block;
}

/**
 * enqueue - adds a new block to a queue
 * @new_block: the new block to push to the top of the stack
 * @stack: the stack to push the new block to
 *
 * Return: nothing
 */

void enqueue(stack_t **new_block, stack_t **stack)
{
    stack_t *crawler = *stack;

    while (crawler->next != NULL)
        crawler = crawler->next;
    crawler->next = *new_block;
    (*new_block)->prev = crawler;
}
/**
 * stoi - converts a string representation of an integer to an interger
 * @str: the string to convert
 *
 * Return: -1 on error, the integer on success
 */

int stoi(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[i] == '-')
		{
			if (str[i + 1] == '\0')
				return (0);
			continue;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			continue;
		else
			return (0);
	}
	return (atoi(str));
}
