#include "monty.h"
/**
 * add - adds top elements of the stack
 * @head: Head of the memory
 * @command_line: Nunmber of lines
 * Return: void
 */
void add(stack_t **head, unsigned int command_line)
{
	int i, j, x;
	stack_t *temp;

	if (*head)
	{
		temp = (*head)->next;
		if (temp)
		{
			i = temp->n;
			j = (*head)->n;
			x = i + j;
			temp->n = x;
			deletenode(head, 0);
			return;
		}
	}
	fprintf(stderr, "L%u: can't add, stack too short\n", command_line);
	erase_else(1), exit(EXIT_FAILURE);
}
