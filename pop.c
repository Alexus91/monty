#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode being
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top);
}
