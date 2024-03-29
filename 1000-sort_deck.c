/*
 * File: 1000-sort duck
 * Author: Sherif Awad
 */
#include "deck.h"

/**
 * sort_deck - sort deck of card
 * @deck: linked list to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *Current;
	size_t len;
	deck_node_t *first, *second, *thered, *forth;

	len = list_len_deck(*deck);

	if (!deck || !*deck || len < 2)
		return;

	Current = *deck;
	while (Current)
	{
		if (Current->prev && card_value(Current) < card_value(Current->prev))
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
				*deck = thered;
			second->prev = thered;
			Current = *deck;
			continue;
		}
		else
			Current = Current->next;
	}
}

/**
 * card_value - value of card
 * @node: card in deck
 * Return: value for card
 */
int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, kind_val = 0;

	for (i = 1; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, val[i - 1]))
			kind_val = i;
	}

	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
			kind_val = kind_val + (13 * i);
	}

	return (kind_val);
}

/**
 * _strcmp - compar strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: -1 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * list_len_deck - get length of list
 * @list: head of list
 * Return: length
 */
size_t list_len_deck(deck_node_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
