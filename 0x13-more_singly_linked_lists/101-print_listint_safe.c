#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the beginning of the list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *current = head;
    const listint_t *next = NULL;

    while (current != NULL)
    {
        count++;
        printf("[%p] %d\n", (void *)current, current->n);
        next = current->next;
        if (next >= current)
        {
            printf("-> [%p] %d\n", (void *)next, next->n);
            exit(98);
        }
        current = next;
    }
    return (count);
}
