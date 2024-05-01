#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **a, listint_t **b)
{
    listint_t *tmp_a = *a;
    listint_t *tmp_b = *b;

    if (tmp_a->prev)
        tmp_a->prev->next = tmp_b;
    if (tmp_b->next)
        tmp_b->next->prev = tmp_a;

    tmp_a->next = tmp_b->next;
    tmp_b->prev = tmp_a->prev;
    tmp_a->prev = tmp_b;
    tmp_b->next = tmp_a;

    *a = tmp_b;
    *b = tmp_a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start = *list;
    listint_t *end = NULL;

    if (list == NULL || *list == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        while (start && start->next != end)
        {
            if (start->n > start->next->n)
            {
                swap_nodes(&start, &(start->next));
                if (!start->prev)
                    *list = start;
                swapped = 1;
                print_list(*list);
            }
            else
            {
                start = start->next;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        end = start;
        while (start && start->prev != NULL)
        {
            if (start->n < start->prev->n)
            {
                swap_nodes(&(start->prev), &start);
                if (!start->prev)
                    *list = start;
                swapped = 1;
                print_list(*list);
            }
            else
            {
                start = start->prev;
            }
        }
    }
}

