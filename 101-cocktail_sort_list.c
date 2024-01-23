#include "sort.h"
#include <stdio.h>

void swap(listint_t **list, listint_t *node);
void cocktail_sort_list(listint_t **list);
/**
 * swap - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 *
 * Return: void
 */
void swap(listint_t **list, listint_t *node)
{
	listint_t *next_node;

	if (node == NULL || node->next == NULL)
		return;

	next_node = node->next;
	node->next = next_node->next;

	if (next_node->next != NULL)
		next_node->next->prev = node;

	next_node->next = node;
	next_node->prev = node->prev;
	node->prev = next_node;

	if (next_node->prev != NULL)
		next_node->prev->next = next_node;
	else
		*list = next_node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	/*listint_t *start = *list*/
	listint_t *end, *start;
	bool swapped = true;

	if (list == NULL || *list == NULL)
		return;
	start = *list;
	while (swapped)
	{
		swapped = false;

		/* Forward pass (bubble sort) */
		while (start->next != NULL)
		{
			if (start->next->n < start->n)
			{
				swap(list, start);
				swapped = true;
				print_list(*list);
			}
			else
			{
				start = start->next;
			}
		}

		if (!swapped)
			break;
		end = start;
		swapped = false;
		/* Backward pass (bubble sort) */
		while (end->prev != NULL)
		{
			if (end->prev->n > end->n)
			{
				swap(list, end->prev);
				swapped = true;
				print_list(*list);
			}
			else
			{
				end = end->prev;
			}
		}
		start = end;
	}
}
