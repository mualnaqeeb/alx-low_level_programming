#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - Prints a linked list
 * @head: Pointer to a struct
 *
 * Return: Number of nodes in list
 */

size_t print_listint_safe(const listint_t *head)
{
    const listint_t *current, *next;
    size_t count = 0;

    if (head == NULL)
        exit(98);

    current = head;

    while (current != NULL)
    {
        printf("[%p] %d\n", (void *)current, current->n);
        count++;

        next = current->next;

        /* Check if the next node has already been visited */
        if (next != NULL && next <= current)
        {
            printf("-> [%p] %d\n", (void *)next, next->n);
            exit(98);
        }

        current = next;
    }

    return (count);
}
