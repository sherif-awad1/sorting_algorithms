/*
 * File:104-heap_sort.c
 * Author: Sherif Awad
 */
#include "sort.h"

/**
 * heap_sort - sortarray with heap sorting algorithm
 * @array: array
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int Sort;

	if (size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		HeapArray(array, size, (size_t)i, size);

	for (i = size - 1; i >= 0; i--)
	{
		Sort = array[i];
		array[i] = array[0];
		array[0] = Sort;
		if (i != 0)
			print_array(array, size);
		HeapArray(array, (size_t)i, 0, size);
	}
}

/**
 * HeapArray - turn array in heap
 * @array: array
 * @size2: size
 * @index: index
 * @size: array size
 */
void HeapArray(int *array, size_t size2, size_t index, size_t size)
{
	size_t Mxem, prev, next;
	int Sort;

	Mxem = index;
	prev = (index * 2) + 1;
	next = (index * 2) + 2;

	if (prev < size2 && array[prev] > array[Mxem])
		Mxem = prev;

	if (next < size2 && array[next] > array[Mxem])
		Mxem = next;

	if (Mxem != index)
	{
		Sort = array[index];
		array[index] = array[Mxem];
		array[Mxem] = Sort;
		print_array(array, size);
		HeapArray(array, size2, Mxem, size);
	}
}
