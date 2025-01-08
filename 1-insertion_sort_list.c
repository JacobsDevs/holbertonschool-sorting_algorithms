#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list using the insertion method.
 * @list: Pointer to the head of the list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *current = *list;
	listint_t *next;
	listint_t *placement;

	if (list == NULL)
		return;
	while (current->next != NULL)
	{
		next = current->next;
		placement = current;
		while (placement != NULL && next->n < placement->n)
		{
			placement->next = next->next;
			if (placement->next != NULL)
				placement->next->prev = placement;
			next->prev = placement->prev;
			if (next->prev != NULL)
				next->prev->next = next;
			else
				head = next;
			next->next = placement;
			placement->prev = next;
			placement = next->prev;
			print_list(head);
			*list = head;
		}
		current = next;
	}
}
