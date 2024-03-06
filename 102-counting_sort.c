/*
 * File: 102-counting_sort.c
 * Author: Sherif Awad
 */
#include "sort.h"

/**
 * counting_sort - sort array with counting sorting algorithm
 * @array: array
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int *ArrayCount, *ArrayOuter, highest, Number, j;
	size_t i;

	if (size < 2)
		return;

	highest = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > highest)
			highest = array[i];

	ArrayCount = malloc(sizeof(size_t) * (highest + 1));
	ArrayOuter = malloc(sizeof(int) * size);

	for (j = 0; j <= highest; j++)
		ArrayCount[j] = 0;
	for (i = 0; i < size; i++)
	{
		Number = array[i];
		ArrayCount[Number] += 1;
	}
	for (j = 1; j <= highest; j++)
		ArrayCount[j] += ArrayCount[j - 1];
	print_array(ArrayCount, highest + 1);
	for (i = 0; i < size; i++)
	{
		ArrayOuter[ArrayCount[array[i]] - 1] = array[i];
		ArrayCount[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = ArrayOuter[i];

	free(ArrayCount);
	free(ArrayOuter);
}
