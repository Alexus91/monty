#include "monty.h"
/**
 * divv - Divides the second top element of the stack by the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode being executed
 */
void divv(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;

	if (b == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = b / a;
	pop(stack, line_number);
}
