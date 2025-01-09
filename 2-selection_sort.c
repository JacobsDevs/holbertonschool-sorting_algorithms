#include "sort.h"
#include <stdio.h>

void selection_sort(int *array, size_t size)
{
	int min = 0;
	int tmp;
	int i = 0;
	int j = 0;

	if (array == NULL)
		return;
	for (i = 0; i <= (int)size - 1; i++)
	{
		min = i;
		for (j = i; j <= (int)size - 1; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min == i)
			continue;
		tmp = array[min];
		array[min] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}

}
