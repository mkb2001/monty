#include "monty.h"



int execute (char * cont, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
			{
				"push", f_push
			}
	};
	unsigned int i = 0;

	char *op;

	op = strtok(cont, "\n\t");
	if (op && op[0] == '#'){
		return (0);

	}

	while (opst[i].opcode && op){
		if (strcmp(op, opst[i].opcode) == 0){
			opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op );
		fclose(file);
		free(cont);
		exit(EXIT_FAILURE);
	}
	return (1);
}
