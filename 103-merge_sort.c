#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays into one sorted array
 * @array: Original array
 * @size: Size of the original array
 * @left: Pointer to the left subarray
 * @size_left: Size of the left subarray
 * @right: Pointer to the right subarray
 * @size_right: Size of the right subarray
 **/
void merge(int *array, size_t size, int *left, size_t size_left, int *right, size_t size_right)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc(sizeof(int) * size);

	if (temp == NULL)
	{
		free(temp);
		return;
	}

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (i < size_left && j < size_right)
	{
		if (left[i] <= right[j])
		{
			temp[k] = left[i];
			i++;
		}
		else
		{
			temp[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < size_left)
	{
		temp[k] = left[i];
		i++;
		k++;
	}

	while (j < size_right)
	{
		temp[k] = right[j];
		j++;
		k++;
	}

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, size);

	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i = 0;
	int *left = NULL;
	int *right = NULL;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;

	left = array;
	right = array + mid;

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(array, size, left, mid, right, size - mid);
}

