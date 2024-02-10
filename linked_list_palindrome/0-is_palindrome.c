#include <stdio.h>
#include "lists.h"


/**
 * is_palindrome - determines whether a linked list is palindrome:
 * @head: pointer to the first node of the linked list.
 *
 * Return: 0 if palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    int l = len(*head);
    int i;
    listint_t *current = *head;
    int array[l];

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    for (i = 0; i < l; i++)
    {
        array[i] = current->n;
        current = current->next;
    }

    for (i = 0; i < l / 2; i++)
    {
        if (array[i] != array[l - i - 1])
            return (0);
    }

    return (1);
}


/**
 * len - gets the length of a linked list.
 * @head: pointer to the first node of the linked list.
 * 
 * Return: linked list length.
 */
int len(listint_t *head)
{
    int l = 0;
    listint_t *c = head;

    while (c)
    {
        l++;
        c = c->next;
    }

    return (l);
}
