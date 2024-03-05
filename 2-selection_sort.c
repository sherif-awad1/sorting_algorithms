/*
 * File: 2-selection_sort.c
 * Author: Sherif Awad
 */
#include "sort.h"

/**
 * selection_sort - sorts array with selection sorting algorithm
 * @array: array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, maen;

	register int Sort;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		maen = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[maen])
				maen = j;
		}
		Sort = array[i];
		array[i] = array[maen];
		array[maen] = Sort;
		if (i != maen)
			print_array(array, size);
	}
}
