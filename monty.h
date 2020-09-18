#ifndef MONTY
#define MONTY
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct central - the central struct of the program to work.
 * @file: File to be opened
 * @line: line inside getline
 * @command_line: line in the command line in the shell.
 * @head: memory to be used, stack or queue
 * @functions: array of op code
 * @mod: different mode.
 */
typedef struct central
{
	FILE *file;
	char *line;
	unsigned int command_line;
	stack_t *head;
	char **functions;
	int mod;
} core;

extern core list;
char **lead(char **line);
void searcher(void);

void erase_a(char **c);
stack_t *add_dnodeint_end(stack_t **head, int n);
stack_t *add_nodeint(stack_t **head, int n);
void erase_else(int determ);
void erase_list(void);

void push(stack_t **head, unsigned int command_line);
void pall(stack_t **stack, unsigned int command_line);

#endif