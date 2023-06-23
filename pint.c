#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the bytecode instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(bu.file);
		free(bu.cont);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
