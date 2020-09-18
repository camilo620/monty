#include "monty.h"
/**
 * erase_a - free array
 * @c: array to be free
 * Return: void
 */
void erase_a(char **c)
{
	unsigned int i;

	for (i = 0; c[i]; i++)
		free(c[i]);
	free(c);
}
/**
 * erase_else - free if is not an array.
 * @determ: Tells if it is an array.
 * Return: void.
 */
void erase_else(int determ)
{
	if (determ == 1)
		erase_a(list.functions);
	free(list.line);
	fclose(list.file);
	erase_list();
}
/**
 * add_dnodeint_end -  Adds a new node at the end of a linked list.
 * @head: the head
 * @n: number to add
 * Return: pointer to the new node.
 */
stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *temp;
	stack_t *list = malloc(sizeof(stack_t));

	if (list)
	{
		list->n = n;
		if (*head)
		{
			for (temp = *head; temp->next; temp = temp->next)
			{
			}
			list->prev = temp;
			temp->next = list;
			list->next = 0;
			return (list);
		}
		*head = list;
		list->next = 0;
		list->prev = 0;
		return (list);
	}
	fprintf(stderr, "Error: malloc failed\n"), erase_else(1);
	exit(EXIT_FAILURE);
}
/**
 * erase_list - free a list
 * Return: void
 */
void erase_list(void)
{
	stack_t *temp, *temp2;

	if (!list.head)
		return;
	for (temp = list.head->next; temp; temp = temp2)
	{
		temp2 = temp->next;
		free(temp);
	}
	free(list.head);
}
/**
 * add_nodeint - adds a new node to the start of a linked list.
 * @head:  the head
 * @n: numebr to be added
 * Return: pointer to the new node.
 */
stack_t *add_nodeint(stack_t **head, int n)
{
	stack_t *list = malloc(sizeof(stack_t));

	if (list)
	{
		list->n = n;
		list->prev = 0;
		list->next = *head;
		if (*head)
			(*head)->prev = list;
		*head = list;
		return (list);
	}
	fprintf(stderr, "Error: malloc failed\n"), erase_else(1);
	exit(EXIT_FAILURE);
}