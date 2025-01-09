#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - entry point.
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 */

void quick_sort(int *array, size_t size)
{
	sort(array, 0, (int)size - 1, size);
}

/**
 * swap - swaps the data in a & b
 * @a: Address to the element a
 * @b: Address to the element b
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sort - Recursvely sorts through the array calling partition
 * at each approporiate step.
 * @array: Pointer to the array.
 * @low: Index of the low value.
 * @high: Index of the high value.
 * @size: Full size of the array
 */

void sort(int *array, int low, int high, size_t size)
{
	int p_index;

	if (low < high)
	{
		p_index = partition(array, low, high, size);

		sort(array, low, p_index - 1, size);
		sort(array, p_index + 1, high, size);
	}
}

/**
 * partition - Partitions the array with values low on the left, high right
 * @array: Pointer to the array to sort.
 * @low: Index to the low point.
 * @high: Index to the high point.
 * @size: Full size of the array.
 *
 * Return: The index the pivot is at
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j = low;

	for (; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
