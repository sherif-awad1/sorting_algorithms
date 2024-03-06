#include "sort.h"

/**
 * quick_sort_hoare - sort array with quick sorting hoare algorithm
 * @array: array
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	QuichHelper(array, 0, (int)size - 1, size);
}

/**
 * QuichHelper - helper function for quick sort hoare
 * @array: array
 * @prev: index of prev element
 * @next: index of next element
 * @size: array size
 */
void QuichHelper(int *array, int prev, int next, size_t size)
{
	int Pivot;

	if (prev < next)
	{
		Pivot = Indexer(array, prev, next, size);
		QuichHelper(array, prev, Pivot - 1, size);
		QuichHelper(array, Pivot, next, size);
	}
}

/**
 * Indexer - get pivot index
 * @array: array
 * @prev: index of prev element
 * @next: index of next element
 * @size: array size
 * Return: index of Pivot element
 */
int Indexer(int *array, int prev, int next, size_t size)
{
	int Sort, pivot = array[next];
	size_t i, j;

	i = prev - 1;
	j = next + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		if (i != j)
		{
			Sort = array[i];
			array[i] = array[j];
			array[j] = Sort;
			print_array(array, size);
		}
	}
	return (0);
}
