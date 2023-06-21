#include "monty.h"

/**
 * initialize_stack - Initializes the stack
 * @stack: Pointer to the stack
 *
 */
void initialize_stack(stack_t **stack)
{
	*stack = NULL;
}

/**
 * free_stack - Frees the stack
 * @stack: Pointer to the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	*stack = NULL;
}

/**
 * is_integer - Checks if a string represents an integer
 * @str: String to be checked
 *
 * Return: 1 if the string represents an integer, 0 otherwise
 */
int is_integer(const char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
	{
		return (0);
	}

	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}

	return (1);
}
