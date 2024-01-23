#include "sort.h"

/**
 * swap_func - swap numbers
 * @idx1: first num
 * @idx2: second num
 * @array: array to be swapped in memmory
 * Return: void
 */

void swap_func(int *array, int idx1, int idx2)
{
int *ptr = array;
int temp;

temp = ptr[idx1];
ptr[idx1] = ptr[idx2];
ptr[idx2] = temp;
}

/**
 * bubble_sort -  bubble sort numbers
 * @size: array size
 * @array: array to be swapped in memmory
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
int i, len = 0;
int *A = array;
bool swapped = false;

len = size;
if (len <= 1)
	return;
do {
swapped = false;
for (i = 1; i < len; i++)
{
if (A[i - 1] > A[i])
{
	swap_func(A, i - 1, i);
	swapped = true;
	print_array(A, len);
}
}

} while (swapped == true);



}
