#include "sort.h"

/**
 * swap_nodes - a helper function that swaps two adjacent nodes of a doubly
 *              linked list.
 * @ptr: a pointer to a node
 * @head: the address of the first node of the list
 * Return: returns the address of the swapped node
 */
listint_t *swap_nodes(listint_t *ptr, listint_t **head)
{
	listint_t *temp;

	temp = ptr->next;
	if (temp->next != NULL)  /* not last node of the list */
		temp->next->prev = ptr;
	temp->prev->next = temp->next;
	temp->next = ptr;
	temp->prev = ptr->prev;
	if (ptr->prev != NULL)  /* not first node of the list */
		ptr->prev->next = temp;
	ptr->prev = temp;

	if (temp->prev == NULL)
		*head = temp;

	return (temp);
}

/**
 * cocktail_sort_list - a function that sorts a list in ascending order using
 *                     coctail shaker sorting algorithm.
 * @list: the list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr;
	int swapped;

	if (!list || !(*list) || (!(*list)->prev && !(*list)->next))
		return;

	ptr = *list;
	do {
		/* forward traversal */
		swapped = 0;
		while (ptr->next->next != NULL)
		{
			if (ptr->n > ptr->next->n)
			{
				ptr = swap_nodes(ptr, list);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			ptr = ptr->next;
		}
		if (!swapped && ptr->n < ptr->next->n)
			break;
		/* backward traversal */
		swapped = 0;
		while (ptr != NULL)
		{
			if (ptr->n > ptr->next->n)
			{
				ptr = swap_nodes(ptr, list);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			ptr = ptr->prev;
		}
		if (!swapped)
			break;
		/* ptr is now == NULL. Reinitialize it to first node */
		ptr = *list;

	} while (swapped);
}
