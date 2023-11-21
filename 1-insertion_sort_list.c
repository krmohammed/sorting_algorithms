#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *ptr, *temp;

	if (*list == NULL || (*list)->next == NULL)
		return;

	temp = *list;

	while (temp)
	{
		ptr = temp->next;
		tmp = temp;
		while (ptr && tmp && tmp->n > ptr->n)
		{
			tmp->next = ptr->next;
			if (ptr->next)
				ptr->next->prev = tmp;
			ptr->next = tmp;
			ptr->prev = tmp->prev;
			if (tmp->prev)
				tmp->prev->next = ptr;
			tmp->prev = ptr;
			if (ptr->prev == NULL)
			{
				temp = ptr;
				*list = ptr;
			}
			else
				temp = ptr->prev;
			print_list(*list);
			tmp = ptr->prev;
		}
		temp = temp->next;
	}
}
