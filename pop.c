
#include "monty.h"

/**
 * pop - removes the element at the top of the stack
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        free_stack_t(stack);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = temp->next;
    /* If the stack is not having only 1 element */
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}
