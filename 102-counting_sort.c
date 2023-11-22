#include "sort.h"

/**
 * counting_sort - counting sort algorithm
 *
 * @array: list of integers
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, k;
	int *count, max;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (j = 0; j <= max; j++)
		count[j] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	print_array((const int *)count, max + 1);

	for (j = 0, k = 0; j <= max; j++)
	{
		while (count[j]-- > 0)
			array[k++] = j;
	}

	free(count);
}
