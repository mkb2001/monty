
#include "monty.h"
/**
* get_opcode - gets the opcode from a line and formats it properly
* @inst_line: the instruction line
*
* Return: pointer to the opcode
*/

char *get_opcode(char *inst_line)
{
	char *opcode;

	if (inst_line == NULL)
		return (NULL);

	/* Strip the newline character */
	inst_line[strlen(inst_line) - 1] = '\0';

	/* Get the opcode */
	opcode = strtok(inst_line, " ");
	return (opcode);
}

/**
* is_empty - checks if an instruction line is empty
* @inst_line: the instruction line
*
* Return: 1 if the instruction line is empty, 0 if not
*/

int is_empty(char *inst_line)
{
	if (is_newline(inst_line) == 1 || is_spaces(inst_line) == 1)
		return (1);
	return (0);
}

/**
* is_spaces - checks if an instruction line is only spaces
* @inst_line: the instruction line
*
* Return: 1 if the instruction line is empty, 0 if not
*/
int is_spaces(char *inst_line)
{
	if (inst_line != NULL)
	{
		while (*inst_line != '\n')
		{
			if (*inst_line != ' ')
				return (0);
			++inst_line;
		}
	}
	return (1);
}
/**
* is_newline - checks if an instruction line is empty
* @inst_line: the instruction line
*
* Return: 1 if the instruction line is empty, 0 if not
*/
int is_newline(char *inst_line)
{
	if (inst_line != NULL)
		if (*inst_line == '\n')
			return (1);
	return (0);
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
