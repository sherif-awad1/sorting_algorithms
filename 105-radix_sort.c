/*
 * File:105-radix_sort.c
 * Author: Sherif Awad
 */
#include "sort.h"

/**
 * radix_sort - sort array with radix sorting algorithm
 * @array: array
 * @size: array size
 */
void radix_sort(int *array, size_t size)
{
	int Max;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	Max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > Max)
			Max = array[i];

	for (lsd = 1; Max / lsd > 0; lsd *= 10)
	{
		SortCount(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * SortCount - count sort LSD
 * @array: array
 * @size: array size
 * @lsd: least signif digit
 */
void SortCount(int *array, size_t size, size_t lsd)
{
	int ArrayCounter[10] = {0}, *TmpArray, l, m;
	size_t k;

	TmpArray = malloc(sizeof(int) * size);

	for (k = 0; k < size; k++)
		ArrayCounter[(array[k] / lsd) % 10]++;
	for (l = 1; l < 10; l++)
		ArrayCounter[l] += ArrayCounter[l - 1];

	for (m = size - 1; m >= 0; m--)
	{
		TmpArray[ArrayCounter[(array[m] / lsd) % 10] - 1] = array[m];
		ArrayCounter[(array[m] / lsd) % 10]--;
	}

	for (k = 0; k < size; k++)
		array[k] = TmpArray[k];

	free(TmpArray);
}
