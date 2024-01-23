#include "sort.h"
void swap(int *a, int *b);
void sift_down(int *array, int start, int end, int size);
void build_heap(int *array, int size);
void heap_sort(int *array, size_t size);

/*Function to swap two elements in an array*/
/**
 * swap - swap the numbers in the heap, root and child nodes
 * @a: int a
 * @b: int b
 * Return: Number
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/*Function to perform the sift-down operation on a heap*/
/**
 * sift_down - heapify and sort the nodes using the sift down
 * @array: array
 * @start: start index
 * @size: size
 * @end: end index
 * Return: NULL
 */
void sift_down(int *array, int start, int end, int size)
{
	int child, swap_index, root = start;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap_index = root;

		if (array[swap_index] < array[child])
			swap_index = child;
		if (child + 1 <= end && array[swap_index] < array[child + 1])
			swap_index = child + 1;

		if (swap_index == root)
		{
			return;
		}
		else
		{
			swap(&array[root], &array[swap_index]);
			print_array(array, size);
			root = swap_index;
		}
	}
}

/*Function to build a max heap from an array*/
/**
 * build_heap - calculate the hierachy needed and build the heap
 * @array: array
 * @size: size of the array
 * Return: NULL
 */
void build_heap(int *array, int size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, i, size - 1, size);
}

/*Function to perform heap sort*/
/**
 * heap_sort - heap sort algorithm
 * @array: array
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	build_heap(array, size);

	for (i = size - 1; i >= 1; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
