#include "sort.h"

/**
 * bubble_sort - Sort a given array using the Bubble
 * sort algorithm in the ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of @array.
 *
 **/
void bubble_sort(int *array, size_t size)
{
	int pass = 0, index = 0;
	int passes_required = 0, last_index = 0;
	int temp = 0;

	if (array == NULL || size < 2)
	{
		return;
	}

	passes_required = size - 1;
	for (pass = 0; pass < passes_required; pass++)
	{
		last_index = size - pass - 1;
		for (index = 0; index < last_index; index++)
		{
			if (array[index] > array[index + 1])
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
