#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 * @head: pointer to a pointer to the head of a linked list
 * @n: integer value to store in the new node
 *
 * Return: pointer to the newly created node, or NULL on failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;

if (!head)
return (NULL);

new_node = malloc(sizeof(listint_t));
if (!new_node)
return (NULL);

new_node->n = n;
new_node->next = *head;
*head = new_node;

return (new_node);
}

