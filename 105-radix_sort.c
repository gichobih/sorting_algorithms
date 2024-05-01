#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Exponent to get the digit at the specified position
 **/
void counting_sort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};
    int i;

    if (output == NULL)
        return;

    for (i = 0; i < (int)size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void radix_sort(int *array, size_t size)
{
    int max = 0;
    int exp;

    if (array == NULL || size < 2)
        return;

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}

