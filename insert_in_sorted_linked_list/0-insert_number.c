#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * instert_node - inserts a node in a numerical sorted singly linked list.
 * @head: pointer to the first node of the list.
 * @number: number to be inserted.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = malloc(sizeof(listint_t));
	listint_t *c = *head;

	if (new)
	{
		new->n = number;
		new->next = NULL;

		if (*head == NULL || (*head)->n >= new->n)
		{
			new->next = *head;
			*head = new;
		}

		else
		{
			if ((*head)->n == new->n)
			{
				free(new);
				return (*head);
			}

			while (c->next && c->next->n < new->n)
				c = c->next;

			new->next = c->next;
			c->next = new;
		}

		return (new);
	}

	free(new);
	return (NULL);
}
