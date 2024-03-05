/*
 * File: 101-cocktail_sort_list.c
 * Author: Sherif Awad
 */
#include "sort.h"

/**
 * list_len - get list length
 * @list: list
 * Return: len
 */
int list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * SwapNodes - swap nodes
 * @list: list
 * @node: node
 */
void SwapNodes(listint_t **list, listint_t **node)
{
	listint_t *first, *second, *thered, *forth;

	first = (*node)->prev;
	second = *node;
	thered = (*node)->next;
	forth = (*node)->next->next;
	second->next = forth;
	if (forth)
		forth->prev = second;
	thered->next = second;
	thered->prev = second->prev;
	if (first)
		first->next = thered;
	else
		*list = thered;
	second->prev = thered;
	*node = thered;
}

/**
 *  cocktail_sort_list - sort linked list with cocktail sorting algorithm
 * @list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	node = *list;
	while (!sorted)
	{
		sorted = 1;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				sorted = 0;
				SwapNodes(list, &node);
				print_list(*list);
			}
			else
				node = node->next;
		}
		if (sorted)
			break;
		node = node->prev;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				sorted = 0;
				node = node->prev;
				SwapNodes(list, &node);
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
