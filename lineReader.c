#include "monty.h"


/**
* lineReader - interpretes a line to determine its operation
* @stack: the stack data structure
* @line: the instruction line to interprete
* @line_number: the number of the instruction in the file
*
* Return: 1 if successfully interpreted, 0 if instruction not found
*/
int lineReader(stack_t **stack, char *line, int line_number)
{
	char *opcode;

	if (is_empty(line) != 0)
		return (0);

	opcode = get_opcode(line);

	/* Handle the nop opcode */
	if (strcmp(opcode, "nop") == 0)
		return (0);

	/* Handle comment */
	if (strncmp(opcode, "#", 1) == 0)
		return (0);

	/* Validate the opcode and call function handler */
	if (ref_func(opcode) == NULL)
		print_errmsg_opcodefail(stack, line_number, opcode);
	else
		ref_func(opcode)(stack, line_number);
	return (0);
}



