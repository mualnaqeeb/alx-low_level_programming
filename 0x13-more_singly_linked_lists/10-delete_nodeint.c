#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index
 * of a listint_t linked list.
 * @head: pointer to the head pointer of the linked list
 * @index: index of the node to delete, starting from 0
 *
 * Return: 1 if succeeded, -1 otherwise
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *prev_node, *current_node;
unsigned int i;

if (head == NULL || *head == NULL)
return (-1);

if (index == 0)
{
current_node = *head;
*head = (*head)->next;
free(current_node);
return (1);
}

prev_node = *head;
current_node = (*head)->next;

for (i = 1; current_node != NULL && i < index; i++)
{
prev_node = current_node;
current_node = current_node->next;
}

if (current_node == NULL)
return (-1);

prev_node->next = current_node->next;
free(current_node);

return (1);
}

