#include "monty.h"
/**
 * push - push a number to the memory
 * @head: Holds the head of the memory
 * @command_line: number of the line
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
 * pall - Prints memory
 * @head: head of the memory
 * @command_line: number of the line
 * Return: void
 */
void pall(stack_t **head, unsigned int command_line)
{
	stack_t *temp = *head;

	(void) command_line;

	for (; temp; temp = temp->next)
		printf("%d\n", temp->n);
}
/**
 * pint - prints the head of the memory
 * @head: head of the memory
 * @command_line: lines on command line
 * Return: void
 */
void pint(stack_t **head, unsigned int command_line)
{
	if (*head)
	{
		printf("%d\n", (*head)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pint, stack empty\n", command_line);
	erase_else(1), exit(EXIT_FAILURE);
}
