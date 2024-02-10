#include <stdbool.h>

#include <stdio.h>
#include "lists.h"

int isPalindromeUtil(listint_t** left, listint_t* right) 
{ 
    if (right == NULL) 
        return (1);
  
    bool isp = isPalindromeUtil(left, right->next);

    if (isp == false) 
        return (0); 
 
    bool isp1 = (right->n == (*left)->n);

    *left = (*left)->next;
 
    return (isp1 ? 1: 0);
} 
 
int is_palindrome(listint_t **head)
{
    listint_t *h = *head;

    return (isPalindromeUtil(&h, h));
}
