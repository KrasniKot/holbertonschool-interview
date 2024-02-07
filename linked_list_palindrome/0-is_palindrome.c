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

    if (l <= 0)
        return (1);

    for (i = 0; i <= (l % 2 == 0) ? l / 2 : (l - 1) / 2; i++)
        if ((*head)[i].n != (*head)[l - i].n)
            return (0);

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

    return (l - 1);
}
