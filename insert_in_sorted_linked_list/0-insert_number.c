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

	if (newNode)
	{
		newNode->n = number;
		newNode->next = NULL;

		if (*head == NULL || (*head)->n >= newNode->n)
		{
			newNode->next = *head;
			*head = newNode;
		}

		else
		{
			while (currentNode->next && currentNode->next->n < newNode->n)
				currentNode = currentNode->next;

			newNode->next = currentNode->next;
			currentNode->next = newNode;
		}

		return (newNode);
	}

	return (NULL);
}
