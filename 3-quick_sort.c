#include "sort.h"
/**
 * swap_quick - swap
 * @a: first data
 * @b: second ...
 * Return: null
 */
void swap_quick(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Function to partition the array
 * and return the index of the pivot
 * @arr: array
 * @low: left partition index
 * @high: right sub array/ pertition index
 * @size: array size
 * Return: NULL
 */
int partition(int *arr, int low, int high, int size)
{
	int pivot = arr[high]; /* Choose the last element as the pivot */
	int i = low; /* Index of the smaller element*/
	int j;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			if (i < j)
			{
			swap_quick(&arr[i], &arr[j]);
			print_array(arr, size);
			}
			i++;
		}
	}
	/*Place the pivot element in its correct position*/
	if (arr[i] > arr[high])
	{
	swap_quick(&arr[i], &arr[high]);
	print_array(arr, size);
	}
	return (i);
}

/**
 * quickSort_helper - Function to perform Quick Sort
 * @arr: ==
 * @low: ==
 * @high: ==
 * @size: ==
 * Return: NULL
 */
void quickSort_helper(int *arr, int low, int high, int size)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, size); /*Partition the array*/

		/* Recursively sort elements before the pivot*/
		quickSort_helper(arr, low, pi - 1, size);
		/*Recursively sort elements after the pivot*/
		quickSort_helper(arr, pi + 1, high, size);
	}
}
/**
 * quick_sort - ====
 * @array: array
 * @size: size of array
 * Return: ===
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort_helper(array, 0, size - 1, size);

}
