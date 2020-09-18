#include "monty.h"
/**
 * deletenode - Deletes a node at indicated point
 * @head: head of the memory
 * @indx: point to delete
 * Return: 1 if succeed, -1 if didn't
 */
int deletenode(stack_t **head, unsigned int indx)
{
	unsigned int i;
	stack_t *temp = *head;
	stack_t *prev = 0;
	stack_t *next = 0;

	for (i = 0; temp; temp = temp->next, i++)
	{
		if (indx == 0)
		{
			if (temp->next)
			{
				next = temp->next;
				next->prev = 0;
			}
			head[0] = next;
			free(temp);
			return (1);
		}
		else if (i == indx)
		{
			prev = temp->prev;
			if (temp->next)
				next = temp->next, next->prev = prev, prev->next = next;
			else
				prev->next = 0;
			free(temp);
			return (1);
		}
	}
	return (-1);
}
