#include "monty.h"
/**
 * push - push a number to the memory
 * @head: Holds the head of the memory
 * @n: number of the line
 * Return: void
 */
void push(stack_t **head, unsigned int command_line)
{
	int i, j = 2;

	if (list.functions[1] != 0)
	{
		for (i = 0; list.functions[1][i]; i++)
		{
			if (!(list.functions[1][i] >= '0' &&
			list.functions[1][i] <= '9') && (list.functions[1][i] != '-'))
			{
				j = 1;
			}
		}
		if (j != 1)
		{
			if (list.mod == 1)
			{
				add_nodeint(head, atoi(list.functions[1]));
				return;
			}
			else if (list.mod == -1)
			{
				add_dnodeint_end(head, atoi(list.functions[1]));
				return;
			}
		}
	}
	fprintf(stderr, "L%u: usage: push integer\n", command_line);
	erase_else(1), exit(EXIT_FAILURE);
}
/**
 * pall - Prints the stack/Queue
 * @stack: Holds the head of the stack
 * @linen: Holds the number of the line
 * Return: none
 */
void pall(stack_t **head, unsigned int command_line)
{
	stack_t *temp = *head;

	(void) command_line;

	for (; temp; temp = temp->next)
		printf("%d\n", temp->n);
}
