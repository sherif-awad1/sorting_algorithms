/*
 * File:103-merge_sort.c
 * Author: Sherif Awad
 */
#include "sort.h"

/**
 * merge_sort - sort array with merge sorting algorithm
 * @array: array
 * @size: array size
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);

	merge_recursion(arr, array, 0, size);
	free(arr);
}

/**
 * MargeHelper - help merge sort array
 * @TmpArray: temper array
 * @array: array
 * @prev: index of prev element
 * @next: index of next element
 */
void MargeHelper(int *TmpArray, int *array, size_t prev, size_t next)
{
	size_t center;

	if (next - prev > 1)
	{
		center = (next - prev) / 2 + prev;
		MargeHelper(TmpArray, array, prev, center);
		MargeHelper(TmpArray, array, center, next);
		ArrayAlice(TmpArray, array, prev, center, next);
	}
}

/**
 * ArrayAlice - array alice
 * @TmpArry: Temp array
 * @arry: array
 * @prv: index of prev element
 * @cntr: index of center element
 * @next: index of next elemen
 */
void ArrayAlice(int *TmpArry, int *arry, size_t prv, size_t cntr, size_t next)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[prv]: ");
	print_array(arry + prv, cntr  - prv);
	printf("[next]: ");
	print_array(arry + cntr, next - cntr);

	for (i = prv, j = cntr; i < cntr && j < next; k++)
	{
		if (arry[i] < arry[j])
			TmpArry[k] = arry[i++];
		else
			TmpArry[k] = arry[j++];
	}

	while (i < cntr)
		TmpArry[k++] = arry[i++];
	while (j < next)
		TmpArry[k++] = arry[j++];

	for (k = prv, i = 0; k < next; k++)
		arry[k] = TmpArry[i++];

	printf("[Done]: ");
	print_array(arry + prv, next - prv);
}
