#include "sort.h"
#include <stddef.h>
#include <sys/types.h>

/**
 *l_partition - Lomuto partition scheme.
 *@array: array of ints
 *@size: size of the array
 *@start: start of the array
 *@end: end of the array
 *Return: returns pivot
 */

size_t l_partition(int *array, size_t size, int start, int end)
{
	int i = start;
	int j = start;
	int pivot = array[end];
	int tmp;

	for (; j < end; j++)
	{
		if (array[j] < pivot)
		{
		if (array[i] != array[j])
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
		i++;
		}
	}

	if (array[i] != array[end])
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}

	return (i);
}
/**
 *recursive_quick_sort - quick_sort recursively
 *@array: array of ints
 *@size: size of the array
 *@start: start of the array
 *@end: end of the array
 */

void recursive_quick_sort(int *array, size_t size, ssize_t start, ssize_t end)
{
	size_t pivot;

	if (start < end)
	{
		pivot = l_partition(array, size, start, end);
		recursive_quick_sort(array, size, start, pivot - 1);
		recursive_quick_sort(array, size, pivot + 1, end);
	}
}
/**
 *quick_sort - function that uses quicl quick_sort algorithm
 *@array: array of numbers to be sorted
 *@size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	recursive_quick_sort(array, size, 0, size - 1);
}
