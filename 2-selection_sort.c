#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in ascending
 * order using selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t new_min_pos, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/* initialize min to the first element of the array */
		new_min_pos = i;
		/* search for a new minimum element in the array */
		for (j = i + 1; j < size; j++)
			if (array[j] < array[new_min_pos])
				new_min_pos = j;

		/* perform swap if a new minimum element was found */
		if (new_min_pos != i)
		{
			temp = array[i];
			array[i] = array[new_min_pos];
			array[new_min_pos] = temp;
			/* print the current state of the array */
			print_array(array, size);
		}
	}
}
