#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode being executed
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;
	bu_t bu = {NULL, NULL, NULL, 0};

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(bu.cont);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
