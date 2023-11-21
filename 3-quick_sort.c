#include "sort.h"

/**
 * partition - partitioning using lomuto scheme
 *
 * @array: list of integers
 * @size: size of array
 * @low: first element
 * @high: last element
 *
 * Return: index of pivot
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	i++;
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;

	if (i != j)
		print_array(array, size);

	return (i);
}

/**
 * q_sort - sorts using quick_sort
 *
 * @array: list of integers
 * @size: size of array
 * @low: first element
 * @high: last element
 */
void q_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (array == NULL || high <= low || size < 2 || low < 0)
		return;

	part = partition(array, size, low, high);
	q_sort(array, size, low, part - 1);
	q_sort(array, size, part + 1, high);
}

/**
 * quick_sort - quick sort algorithm using
 * Lomuto partition scheme
 *
 * @array: list on integers
 * @size: number of integers in array
 */

void quick_sort(int *array, size_t size)
{
	q_sort(array, size, 0, size - 1);
}
