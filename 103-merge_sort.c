#include "sort.h"

void merge_subarray(int *subarray, int *temp,
		size_t start, size_t mid, size_t end);
void merge_sort_recursive(int *subarray,
		int *temp, size_t start, size_t end);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - Sorts a subarray of integers.
 * @subarray: The subarray to sort.
 * @temp: A temp buffer
 * @start: The starting index
 * @mid: The middle index
 * @end: The ending index
 */
void merge_subarray(int *subarray, int *temp,
		size_t start, size_t mid, size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + start, mid - start);

	printf("[right]: ");
	print_array(subarray + mid, end - mid);

	for (i = start, j = mid; i < mid && j < end; k++)
		temp[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < mid; i++)
		temp[k++] = subarray[i];
	for (; j < end; j++)
		temp[k++] = subarray[j];
	for (i = start, k = 0; i < end; i++)
		subarray[i] = temp[k++];

	printf("[Done]: ");
	print_array(subarray + start, end - start);
}

/**
 * merge_sort_helper -  recurse the merge sort
 * @subarray: subarra
 * @temp: A temp to store the sorted subarray.
 * @start: The starting index
 * @end: The ending index
 */
void merge_sort_helper(int *subarray, int *temp, size_t start, size_t end)
{
	size_t mid;


	if (end - start > 1)
	{
		mid = start + (end - start) / 2;
		merge_sort_helper(subarray, temp, start, mid);
		merge_sort_helper(subarray, temp, mid, end);
		merge_subarray(subarray, temp, start, mid, end);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the merge sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	merge_sort_helper(array, temp, 0, size);
	free(temp);
}
