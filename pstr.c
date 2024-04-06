/** CODE to implement printing the ASCII value of all elements of the stack */

#include "monty.h"

/**
 * pstr - prints the Ascii value of the top of the stack
 * @stack: the stack data structure to print
 * @line_number: the line number of the instruction in the MBCF
 *
 * Return: nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	int val;
	stack_t *crawler;
	(void)line_number;

	if (*stack == NULL)
		printf("\n");
	else
	{
		crawler = *stack;
		while (crawler != NULL)
		{
			val = crawler->n;
			if (val > 0 && val <= 127)
			{
				printf("%c", val);
				crawler = crawler->next;
			}
			else
				break;
		}
		printf("\n");
	}
}
