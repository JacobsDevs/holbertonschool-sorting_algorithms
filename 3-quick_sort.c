#include "sort.h"
#include <stdio.h>

void quick_sort(int *array, size_t size)
{
	sort(array, 0, (int)size - 1);
}

void swap(int *a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int *array, int low, int high)
{
	int p_index;

	if (low < high)
	{
		p_index = partition(array, low, high);

		sort(array, low, p_index - 1);
		sort(array, p_index + 1, high);
	}
}

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int j = low;

	for (; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, 10);
	return (i + 1);
}
