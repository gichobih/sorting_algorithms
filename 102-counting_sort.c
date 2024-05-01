#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int max = 0, i;
    int *count = NULL;
    int *output = NULL;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create count array to store count of each number */
    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
        return;

    /* Initialize count array */
    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Store count of each number in count array */
    for (i = 0; i < (int)size; i++)
        count[array[i]]++;

    /* Print the count array */
    printf("%d", count[0]);
    for (i = 1; i <= max; i++)
        printf(", %d", count[i]);
    printf("\n");

    /* Modify the count array to store the actual position of each element */
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Create the output array */
    output = malloc(sizeof(int) * size);
    if (output == NULL)
    {
        free(count);
        return;
    }

    /* Build the output array */
    for (i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted elements into the original array */
    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    /* Free allocated memory */
    free(count);
    free(output);
}

