/*
 * File: 3-quick_sort.c
 * Author: Sherif Awad
 */
#include "sort.h"

int Indexer(int *array, int prev, int next, size_t size);
void QuichHelper(int *array, int prev, int next, size_t size);

/**
 * quick_sort - sort array with quick sorting algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	QuichHelper(array, 0, (int)size - 1, size);
}

/**
 * QuichHelper - helper func for quicksort
 * @array: array to sort
 * @prev: index of prev element
 * @next: index of next element
 * @size: size of array
 */
void QuichHelper(int *array, int prev, int next, size_t size)
{
	int Pivot;

	if (prev < next)
	{
		Pivot = Indexer(array, prev, next, size);
		QuichHelper(array, prev, Pivot - 1, size);
		QuichHelper(array, Pivot + 1, next, size);
	}
}

/**
 * Indexer - give Pivot index to quicksort
 * @array: array to search for Pivot
 * @prev: index of prev element
 * @next: index of next element
 * @size: array size
 * Return: index pivot element
 */
int Indexer(int *array, int prev, int next, size_t size)
{
	int Sort, i;
	int j;

	i = prev - 1;

	for (j = prev; j < next; j++)
	{
		if (array[j] < array[next])
		{
			i++;
			if (i != j)
			{
				Sort = array[i];
				array[i] = array[j];
				array[j] = Sort;
				print_array(array, size);
			}
		}
	}

	if (array[next] < array[i + 1])
	{
		Sort = array[i + 1];
		array[i + 1] = array[next];
		array[next] = Sort;
		print_array(array, size);
	}

	return (i + 1);
}
