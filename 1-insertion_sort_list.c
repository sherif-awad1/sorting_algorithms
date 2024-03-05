/*
 * File: 1-insertion_sort_list.c
 * Author: Sherif Awad
*/
#include "sort.h"

/**
 * list_len - get linked list leng
 * @list: list
 * Return: len of list
 */
int list_len(listint_t *list)
{
	int len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * insertion_sort_list - sorts linked list with Insert Sorting algorithm
 * @list: pointer to list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *Current = NULL, *first = NULL;
	listint_t *second = NULL, *thered = NULL, *forth = NULL;

	if (!list || !(*list) || list_len(*list) < 2)
		return;

	Current = *list;

	while (Current)
	{
		if (Current->prev && Current->n < Current->prev->n)
		{
			first = Current->prev->prev;
			second = Current->prev;
			thered = Current;
			forth = Current->next;

			second->next = forth;
			if (forth)
				forth->prev = second;
			thered->next = second;
			thered->prev = first;
			if (first)
				first->next = thered;
			else
				*list = thered;
			second->prev = thered;
			Current = *list;
			print_list(*list);
			continue;
		}
		else
			Current = Current->next;
	}
}
