#include "monty.h"

/**
 * pall - prints the elements in a stack in a LIFO way
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *crawler;
    (void)line_number;

    if (*stack != NULL)
    {
        crawler = *stack;
        while (crawler != NULL)
        {
            printf("%d\n", crawler->n);
            crawler = crawler->next;
        }
    }
}