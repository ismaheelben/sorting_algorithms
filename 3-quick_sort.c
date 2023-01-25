#include "sort.h"

/**
 * swap - a helper function that swaps two integers if they are different
 * @x: the first integer
 * @y: the second integer
 * Return: returns 0 if x == y, otherwise 1.
 */
int swap(int *x, int *y)
{
	int temp = *x;

	if (*x == *y)
		return (0);
	*x = *y;
	*y = temp;
	return (1);
}

/**
 * partition - a helper function that partitions an array into two parts
 * @array: the array to be partitioned
 * @low: the lower bound of the array
 * @high: the upper bound of the array
 * @fixed_size: a variable containing the original length of the array.
 * Return: returns the index of the pivot value.
 */
int partition(int array[], int low, int high, size_t fixed_size)
{
	int i, j, pivot_value, n;

	pivot_value = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			if (i == j)
			{
				i++;
				continue;
			}
			swap(&array[j], &array[i]);
			print_array(array, fixed_size);
			i++;
		}
	}

	n = swap(&array[i], &array[high]);
	if (n)
		print_array(array, fixed_size);
	return (i);
}

/**
 * quicksort_recursion - a helper function that calls itself recursively
 * @array: the array to be sorted
 * @low: the lower bound of the array
 * @high: the higher bound of the array
 * @fixed_size: a variable containing the original length of the array
 */
void quicksort_recursion(int array[], int low, int high, size_t fixed_size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, fixed_size);

		/* sort left hand side */
		quicksort_recursion(array, low, pivot_index - 1, fixed_size);

		/* sort right hand side */
		quicksort_recursion(array, pivot_index + 1, high, fixed_size);
	}
}

/**
 * quick_sort - a function that sorts an array of integers inascending order
 * using quick sort algorithm
 * @array: to array to be sorted
 * @size: the size of @array
 */
void quick_sort(int *array, size_t size)
{
	int fixed_size = size;

	if (size < 2 || array == NULL)
		return;

	quicksort_recursion(array, 0, size - 1, fixed_size);
}
