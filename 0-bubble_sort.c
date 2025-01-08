#include "sort.h"

/**
 * bubble_sort - Uses a bubble sort algorithm to sort the provided array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i;
	int temp;
	int change_made;

	do {
		change_made = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				change_made = 1;
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	} while (change_made == 1);
}
