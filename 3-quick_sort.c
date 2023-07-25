#include "sort.h"

/**
 * quick_sort - Sort a given array using the Quick
 * sort algorithm in the ascending order.
 *
 * @array: The array to be sorted.
 * @size: Thei size of @array.
 *
 **/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	sort_partition(array, size, 0, size - 1);
}

/**
 * sort_partition - Sort the partitions in the array.
 *
 * @array: The array to be sorted.
 * @size: The size for the array.
 * @first: The index of the first element in the
 * sublist (partition in the array).
 * @last: The index of the last element in the
 * sublist (partition in the array).
 *
 **/
void sort_partition(int *array, int size, int first, int last)
{
	int pivot = 0;

	if (first < last)
	{
		pivot = get_pivot_index(array, size, first, last);
		if (pivot - first > 1)
		{
			sort_partition(array, size, first, pivot - 1);
		}
		if (last - pivot > 1)
		{
			sort_partition(array, size, pivot + 1, last);
		}
	}
}

/**
 * swap - Swaps the items at index @first_index with
 * the item at index at @second_index.
 *
 * @array: A pointer to the array of integers.
 * @first_index: The first element's index.
 * @second_index: The second element's index.
 *
 **/
void swap(int **array, int first_index, int second_index)
{
	int temp = 0;

	temp = (*array)[first_index];
	(*array)[first_index] = (*array)[second_index];
	(*array)[second_index] = temp;
}

/**
 * get_pivot_index - Determine the index for the next
 * pivot in the sublist.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @first: The index of the first element in the
 * sublist (partition in the array).
 * @last: The index of the last element in the
 * sublist (partition in the array).
 *
 * Return: The index for the new pivot.
 *
 **/
int get_pivot_index(int *array, size_t size, int first, int last)
{
	int pivot = 0;
	int left = 0, new_pivot = 0;

	pivot = last;
	left = first;
	new_pivot = first - 1;

	for (; left < last; left++)
	{
		if (array[left] <= array[pivot])
		{
			new_pivot++;
			if (new_pivot != left)
			{
				swap(&array, new_pivot, left);
				print_array(array, size);
			}
		}
	}
	if ((new_pivot + 1) != last)
	{
		swap(&array, new_pivot + 1, last);
		print_array(array, size);
	}
	return (new_pivot + 1);
}

