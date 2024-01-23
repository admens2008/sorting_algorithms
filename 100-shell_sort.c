#include "sort.h"
/**
 * swap - swap values
 * @a: val a
 * @b: val b
 * Return: Void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - shell sort
 * @array: array
 * @size: size
 */
void shell_sort(int *array, size_t size)
{
	/* Generate the Knuth sequence for intervals */
	int interval = 1;
	size_t i;
	int size2 = size;
	int temp, j;

	if (array == NULL || size < 2)
		return;
	while (interval <= size2 / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		/* Perform insertion sort with the current interval */
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}

		/* Print the array at each interval step */
		/* printf("Array after interval %d: ", interval); */
		/*for (size_t i = 0; i < size; i++) {*/
		/*   printf("%d ", array[i]);*/
		/*}*/
		print_array(array, size);

		/*Update the interval using the Knuth sequence*/
		interval = (interval - 1) / 3;
	}
}
