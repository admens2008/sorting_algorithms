#include "sort.h"
#include <stdbool.h>
int getMax(int a[], int n);
void countingSort(int a[], int n, int place);
void radix_sort(int *array, size_t size);
/**
 * is_sorted - check if array is sorted
 * @array: array
 * @size: array size
 * Return: bool
 */
bool is_sorted(int *array, size_t size)
{
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] < array[i - 1])
			return (false);
	}

	return (true);
}
/**
 * getMax - max number
 * @a: array
 * @n: int size
 * Return: int max
 */
int getMax(int a[], int n)
{
	int max = a[0];
	int i;

	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return (max); /* maximum element from the array*/
}
/**
 * countingSort - counting sort strategy
 * @a: array
 * @n: n
 * @place: place value 1s, 10s, 100s
 */
void countingSort(int a[], int n, int place)
{
	int output[1024];
	int count[1024] = {0};
	int i;
	/*int placeincrement = 0;*/

	/*output = malloc((n + 3) * sizeof(int));*/
	/*if (output == NULL)*/
		/*return;*/

	/* Calculate count of elements*/
	for (i = 0; i < n; i++)
		count[(a[i] / place) % 10]++;

	/* Calculate cumulative frequency*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Place the elements in sorted order*/
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / place) % 10] - 1] = a[i];
		count[(a[i] / place) % 10]--;
		/*placeincrement = 1;*/
	}

	for (i = 0; i < n; i++)
		a[i] = output[i];

	print_array(a, n);

	/*free(output);*/
}
/**
 * radix_sort - radix sort
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	/* get maximum element from array */
	int max;
	int place;

	if (array == NULL || size < 2)
		return;
	 max = getMax(array, size);
	/* Apply counting sort to sort elements based on place value*/
	for (place = 1; max / place > 0; place *= 10)
		countingSort(array, size, place);
}
