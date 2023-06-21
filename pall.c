#include "monty.h"

/**
 * pall - Print all elements of the stack
 * @stack: Pointer to the stack
 *
 * This function prints all elements of the stack, starting from the top.
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
