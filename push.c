#include "monty.h"
/**
 * push - Pushes a value onto the stack
 * @stack: Pointer to the stack
 * @value: Value to be pushed onto the stack
 *
 * Return: void
 */
void push(stack_t **stack, int value, bu_t bu)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bu.file);
		free(bu.cont);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
