#include <stdio.h>
#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list.
 * @h: pointer to the first node of the linked list.
 *
 * Return: number of elements in the list.
 */
size_t listint_len(const listint_t *h)
{
    size_t count = 0;

    while (h)
    {
        count++;
        h = h->next;
    }
    return (count);
}

/**
 * is_palindrome - determines whether a linked list is palindrome:
 * @head: pointer to the first node of the linked list.
 *
 * Return: 1 if palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    int len = listint_len(*head);
    int i;
    listint_t *current = *head;
    int array[len];

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    for (i = 0; i < len; i++)
    {
        array[i] = current->n;
        current = current->next;
    }

    for (i = 0; i < len / 2; i++)
    {
        if (array[i] != array[len - i - 1])
            return (0);
    }

    return (1);
}

