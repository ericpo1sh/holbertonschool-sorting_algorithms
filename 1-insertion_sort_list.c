#include "sort.h"
/**
 * insertion_sort_list - insertion sorts the LIST of elements
 * @list: the list that holds the integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *crnt, *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	for (crnt = *list; crnt; crnt = crnt->next)
	{
		for (; crnt->next && crnt->n > crnt->next->n; print_list(*list))
		{
			temp = crnt->next;
			crnt->next = temp->next;
			temp->prev = crnt->prev;
			if (crnt->prev)
				crnt->prev->next = temp;
			if (temp->next)
				temp->next->prev = crnt;
			crnt->prev = temp;
			temp->next = crnt;
			if (temp->prev)
				crnt = temp->prev;
			else
				*list = temp;
		}
	}
}
