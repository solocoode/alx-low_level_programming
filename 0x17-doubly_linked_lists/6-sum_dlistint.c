#include "lists.h"

/**
 *  sum_dlistint - returns sum of all
 * the data (n) of a dlistint_t linked list.
 * @head: double ptr to the head of the list
 *
 * Return: if list is empty, return 0
 */

int sum_dlistint(dlistint_t *head)
{

	int sum = 0;
	dlistint_t *i;

	for (i = head; i != NULL; i = i->next)
	{
		sum += i->n;
	}

	return (sum);
}
