#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define OPCODE_SIZE 10

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stack;
/**
 * struct bu_t - variables args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @cont: line content
 * @lifi: flag change stack
 */

typedef struct bu_t
{
	char *arg;
	FILE *file;
	char *cont;
	int lifi;
} bu_t;
extern bu_t bu;

/* Function prototypes */
void pop(stack_t **stack, unsigned int line_number);
void process_bytecode(FILE *bytecodeFile, stack_t **stack);
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void free_stack(stack_t **stack);
int is_integer(const char *str);
void init_stack(stack_t **stack);
void initialize_stack(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
int process_push(FILE *bytecodeFile, stack_t **stack,
		int *argument, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divv(stack_t **stack, unsigned int line_number);
int execute_opcode(const char *opcode, FILE *bytecodeFile, stack_t **stack
		, int *argument, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
