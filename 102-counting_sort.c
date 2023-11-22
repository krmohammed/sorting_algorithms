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
	int j, *count, *opt, max;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	opt = malloc(sizeof(int) * size);
	if (opt == NULL)
		return;

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (j = 0; j <= max; j++)
		count[j] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array((const int *)count, max + 1);

	for (i = 0; i < size; i++)
	{
		opt[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = opt[i];

	free(count);
	free(opt);
}
