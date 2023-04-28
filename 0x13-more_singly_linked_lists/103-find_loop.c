#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the linked list
 * Return: address of the node where the loop starts, or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
  listint_t *slow = head;
  listint_t *fast = head;
  while (slow != NULL && fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      break;
    }
  }
  if (slow == NULL || fast == NULL || fast->next == NULL)
  {
    return NULL;
  }
  slow = head;
  while (slow != fast)
  {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}