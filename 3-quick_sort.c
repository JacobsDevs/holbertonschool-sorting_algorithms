#include "sort.h"
#include <stdio.h>

void quick_sort(int *array, size_t size)
{
	sort(array, 0, (int)size - 1, size);
}

void swap(int *a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

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
