#include "monty.h"
/**
 * mul - multiplies the top two elements of the stack.
 * @stack: stack
 * @line_number: head
 * Return: no return
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *hi;
	int len = 0, a;
	bu_t bu = {NULL, NULL, NULL, 0};

	hi = *stack;

	while (hi)
	{
		hi = hi->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bu.file);
		free(bu.cont);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	hi = *stack;
	a = hi->next->n * hi->n;
	hi->next->n = a;
	*stack = hi->next;
	free(hi);
}
