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

	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = *head;

	while (c->next && c->next->n < number)
		c = c->next;

	new->next = c->next;
	c->next = new;

	return (new);
}
