#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 *
 * @array: list of items
 * @size: number of items in array
 */
void bubble_sort(int *array, size_t size)
{
	int temp, swp = 1;
	size_t i = size, j;

	if (array == NULL || size <= 1)
		return;

	while (swp)
	{
		swp = 0;
		for (j = 0; j < i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swp = 1;
				print_array(array, size);
			}
		}
		i--;
	}
}
