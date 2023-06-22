#include "monty.h"
/**
 * add - Adds the top two elements of the stack
 *
 * @stack: Pointer to the stack
 * @line_number: Line number of the bytecode instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result = (*stack)->n + (*stack)->next->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n = result;
}
