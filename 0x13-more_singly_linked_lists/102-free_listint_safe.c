#include "lists.h"
/**
 * free_listint_safe - frees a linked list of listint_t nodes
 * @h: pointer to a pointer to the head of the list
 * Return: the number of nodes that were freed
 */

size_t free_listint_safe(listint_t **h) {
  size_t n = 0;
  listint_t *current = *h;
  while (current != NULL) {
    listint_t *next = current->next;
    free(current);
    current = next;
    n++;
  }
  *h = NULL;
  return n;
}
