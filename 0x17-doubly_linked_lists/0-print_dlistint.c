#include "lists.h"

/**
 * print_dlistint - prints all elements of dlistint_t list.
 * @h: ptr to the head of the list
 *
 * Return: num of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{

	int counter = 0;

	if (h == NULL)
		return (counter);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		counter++;
	}

	return (counter);
}
