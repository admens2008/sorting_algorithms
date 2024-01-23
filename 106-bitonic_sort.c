#include "sort.h"
void bitonic_sequence(int *array, size_t size,
		size_t start, size_t seq, char flow);
/**
 * swap_ints - swap values
 * @a: int a
 * @b: int b
 * Return: NULL
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
/**
 * bitonic_merge - bitonic merge
 * @start: start index
 * @array: array
 * @size: size of array
 * @seq: sequence
 * @flow: direction
 */
void bitonic_merge(int *array, size_t size,
		size_t start, size_t seq, char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == 'U' && array[i] > array[i + jump]) ||
					(flow == 'D' && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}
/**
 * bitonic_sequence - sequence
 * @array: array
 * @size: aray size
 * @start: Start index
 * @seq: sequence
 * @flow: up or downward flow
 */
void bitonic_sequence(int *array, size_t size,
		size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == 'U') ? "UP" : "DOWN";
	size_t i;

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		for (i = start; i < start + seq; i++)
		{
			printf("%d", array[i]);
			if (i != start + seq - 1)
				printf(", ");
		}
		printf("\n");

		bitonic_sequence(array, size, start, cut, 'U');
		bitonic_sequence(array, size, start + cut, cut, 'D');
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		for (i = start; i < start + seq; i++)
		{
			printf("%d", array[i]);
			if (i != start + seq - 1)
				printf(", ");
		}
		printf("\n");
	}
}
/**
 * bitonic_sort - bitonic sort algorithm
 * @array: array
 * @size: array size
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, 'U');
}
