#include "sort.h"
void swap(int *arr, int i, int j);
int partition(int *array, int start, int end, size_t size);
void quickSorthelper(int *arr, int start, int end, size_t size);
void quickSort(int *arr, int size);
/**
 * swap - swap values
 * @arr: array
 * @i: int i
 * @j: int j
 */
void swap(int *arr, int i, int j)
{
	int temp = arr[i];

	arr[i] = arr[j];
	arr[j] = temp;
}
/**
 * partition - partition the array into subs
 * @array: array
 * @start: start index
 * @end: last index
 * @size: size of array
 * Return: int
 */
int partition(int *array, int start, int end, size_t size)
{
	int i, j, pivot;

	pivot = array[end];
	i = start - 1;
	j = end + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i == j)
			return (j - 1);
		else if (i > j)
			return (j);

		swap(array, i, j);
		print_array(array, size);
	}
}
/**
 * quickSorthelper - helper function
 * @arr: array
 * @start: start index
 * @end: end index
 * @size: size of array
 * Return: NULL
 */
void quickSorthelper(int *arr, int start, int end, size_t size)
{
	int pi;

	if (start < end)
	{
		pi = partition(arr, start, end, size);
		quickSorthelper(arr, start, pi, size);
		quickSorthelper(arr, pi + 1, end, size);
	}
}
/**
 * quick_sort_hoare - quick sort hoare method
 * @arr: array
 * @size: array size
 */
void quick_sort_hoare(int *arr, int size)
{
	if (!arr || size < 2)
		return;
	quickSorthelper(arr, 0, size - 1, size);

}
