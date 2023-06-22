#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode being executed
 *
 * Description: The swap opcode swaps the positions of the top two elements
 * on the stack. If the stack contains less than two elements, it prints an
 * error message and exits with EXIT_FAILURE.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
