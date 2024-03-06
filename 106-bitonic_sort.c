/*
 * File:106-bitonic_sort.c
 * Author: Sherif Awad
 */
#include "sort.h"

/**
 * bitonic_sort - sort array with bitonic sorting algorithm
 * @array: array
 * @size: array size
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	BitonicHelprt(array, 0, size - 1, 1, size);
}

/**
 * BitonicHelprt - help bitonic sort
 * @array: array
 * @l: index prev element
 * @r: index next element
 * @direction: direction of sorting
 * @size: array size
 */
void BitonicHelprt(int *array, int l, int r, int direction, size_t size)
{
	int way;

	if (r - l >= 1)
	{
		way = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
		BitonicHelprt(array, l, way, 1, size);
		BitonicHelprt(array, way + 1, r, 0, size);
		BitonicCompain(array, l, r, direction);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * BitonicCompain - compain sequence right order
 * @array: array
 * @l: index of prev element
 * @r: index of next element
 * @direction: direction to move
 */
void BitonicCompain(int *array, int l, int r, int direction)
{
	int Sort, i, way = (l + r) / 2, mid = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (i = l; i < l + mid; i++)
		{
			if (direction == (array[i] > array[i + mid]))
			{
				Sort = array[i + mid];
				array[i + mid] = array[i];
				array[i] = Sort;
			}
		}
		BitonicCompain(array, l, way, direction);
		BitonicCompain(array, way + 1, r, direction);
	}

}
