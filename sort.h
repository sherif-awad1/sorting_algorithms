#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
/*
 * File: sort.h
 * Author: Sherif Awad
*/
/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
int list_len(listint_t *list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int Indexer(int *array, int prev, int next, size_t size);
void QuichHelper(int *array, int prev, int next, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void SwapNodes(listint_t **list, listint_t **node);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void MargeHelper(int *TmpArray, int *array, size_t prev, size_t next);
void ArrayAlice(int *TmpArry, int *arry, size_t prv, size_t cntr, size_t next);















#endif
