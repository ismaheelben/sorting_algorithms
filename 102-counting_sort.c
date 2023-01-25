#include "sort.h"

/**
 * max - a helper function that returns the maximum element of @array
 * @array: the array to be searched
 * @size: the size of @array
 * Return: the maximux element
 */
int max(int array[], size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 *_calloc - this is a calloc function
 *@nmemb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	int *p;

	if (nmemb == 0 || size == 0)
		return ('\0');

	p = malloc(nmemb * size);
	if (p == NULL)
		return ('\0');

	for (i = 0; i < nmemb; i++)
		p[i] = 0;

	return (p);
}

/**
 * counting_sort - this is a counting sort method implementation
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int index, maximum = 0, *counter = '\0', *tmp = '\0';
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* find maximum number */
	maximum = max(array, size);
	counter = _calloc(maximum + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));

	/* count the array elements */
	for (i = 0; i < size; i++)
		counter[array[i]]++;

	/* get the accumulative values */
	for (index = 1; index <= maximum; index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximum + 1);

	/* get the new array sorted */
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	/* replace old array to new array sorted */
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
	free(counter);

}
