#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The main function that sorts the given integer array arr[] in*/
/* ascending order*/
/**
 * findMax - find max
 * @arr: array
 * @size: size
 * Return: int
 */
int findMax(int arr[], int size)
{
	int max = arr[0];  /*Assume the first element as the maximum*/
	int i;

		for (i = 1; i < size; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];  /*Update the maximum if found*/
			}
		}

	return (max);
}
/**
 * counting_sort - count sort
 * @arr: array
 * @size: size
 * Return: NULL
 */
void counting_sort(int *arr, size_t size)
{
	/*The output integer array that will have the sorted elements*/
	int i, largenum, size2 = size;
	int *count, *output;

	if (arr == NULL || size < 2)
		return;
	largenum = findMax(arr, size);
	/* Create a count array to store the count of individual*/
	/* elements and initialize count array as 0*/

	count = malloc(sizeof(int) *  largenum + 1);
	output = malloc(sizeof(int) * size2);
	/* Store count of each element*/
	for (i = 0; i < size2; ++i)
		++count[arr[i]];
	/* Change count[i] so that count[i] now contains the actual*/
	/* position of this element in the output array*/
	for (i = 1; i < largenum + 1; ++i)
		count[i] += count[i - 1];
	for (i = 0; i < largenum + 1; ++i)
	{
		if (i < largenum)
			printf("%d, ", count[i]);
		else
			printf("%d", count[i]);
	}
	printf("\n");
	/* Build the output array*/
	for (i = size - 1; i >= 0; --i)
	{
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}
	/* Copy the output array to arr, so that arr now contains*/
	/* the sorted elements*/
	for (i = 0; i < size2; ++i)
		arr[i] = output[i];

	free(count);
	free(output);
}
