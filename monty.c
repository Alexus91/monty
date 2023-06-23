#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *bytecodeFile;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}
	bytecodeFile = fopen(argv[1], "r");
	if (bytecodeFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	init_stack(&stack);
	process_bytecode(bytecodeFile, &stack);
	fclose(bytecodeFile);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
/**
 * process_bytecode - Process the bytecode instructions
 * @bytecodeFile: Pointer to the bytecode file
 * @stack: Pointer to the stack
 */
void process_bytecode(FILE *bytecodeFile, stack_t **stack)
{
	char opcode[OPCODE_SIZE];
	int argument;
	unsigned int line_number = 1;

	while (fscanf(bytecodeFile, "%s", opcode) != EOF)
	{
		if (!execute_opcode(opcode, bytecodeFile, stack, &argument, line_number))
			return;
		line_number++;
	}
}
/**
 * execute_opcode - Execute the specific opcode
 * @opcode: The opcode to execute
 * @bytecodeFile: Pointer to the bytecode file
 * @stack: Pointer to the stack
 * @argument: Pointer to the argument value
 * @line_number: Current line number in the bytecode
 *
 * Return: 1 on success, 0 on failure
 */
int execute_opcode(const char *opcode, FILE *bytecodeFile, stack_t **stack,
		int *argument, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (!process_push(bytecodeFile, stack, argument, line_number))
			return (0);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "sub") == 0)
	{
		sub(stack, line_number);
	}
	else if (strcmp(opcode, "div") == 0)
	{
		divv(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (0);
	}
	return (1);
}
/**
 * init_stack - Initialize the stack
 * @stack: Pointer to the stack
 */
void init_stack(stack_t **stack)
{
	*stack = NULL;
}

/**
 * process_push - Process the 'push' opcode
 * @bytecodeFile: Pointer to the bytecode file
 * @stack: Pointer to the stack
 * @argument: Pointer to the argument value
 * @line_number: Current line number in the bytecode
 *
 * Return: 1 on success, 0 on failure
 */
int process_push(FILE *bytecodeFile, stack_t **stack
		, int *argument, unsigned int line_number)
{
	if (fscanf(bytecodeFile, "%d", argument) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bytecodeFile);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	push(stack, *argument);
	return (1);
}
