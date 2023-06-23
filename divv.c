#include "monty.h"

/**
 * divv - Divides the second top element of the stack by the top element
 * @stack: Pointer to the stack
 * @line_number: Line number of the bytecode instruction
 */
void divv(stack_t **stack, unsigned int line_number)
{
	bu_t bu = {NULL, NULL, NULL, 0};
	int result = (*stack)->next->n / (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(bu.file);
		free_stack(stack);
		free(bu.cont);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bu.file);
		free_stack(stack);
		free(bu.cont);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
	(*stack)->n = result;
}
