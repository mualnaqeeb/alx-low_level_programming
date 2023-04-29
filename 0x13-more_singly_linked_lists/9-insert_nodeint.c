#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: value of the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *prev_node, *current_node;
unsigned int i;

/* Create new node */
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return NULL;
new_node->n = n;

/* Traverse to node before given index */
prev_node = NULL;
current_node = *head;
for (i = 0; i < idx && current_node != NULL; i++)
{
prev_node = current_node;
current_node = current_node->next;
}

/* Check if node exists */
if (i != idx)
{
free(new_node);
return NULL;
}

/* Insert new node */
if (prev_node == NULL)
*head = new_node;
else
prev_node->next = new_node;
new_node->next = current_node;

return new_node;
}
