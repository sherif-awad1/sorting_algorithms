/*
 * File: 100-shell_sort.c
 * Author: Sherif Awad
 */
#include "sort.h"

/**
* shell_sort - sort array with shell sorting algorithm
* @array: array
* @size: size of array
*/
void shell_sort(int *array, size_t size)
{
	size_t Diffre = 0, j, i;
	int Sort;

	if (size < 2)
		return;

	while ((Diffre = Diffre * 3 + 1) < size)
		;

	Diffre = (Diffre - 1) / 3;

	for (; Diffre > 0; Diffre = (Diffre - 1) / 3)
	{
		for (i = Diffre; i < size; i++)
		{
			Sort = array[i];
			for (j = i; j >= Diffre && Sort <= array[j - Diffre]; j -= Diffre)
				array[j] = array[j - Diffre];
			array[j] = Sort;
		}
		print_array(array, size);
	}
}
