#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int partition(int *array, int low, int high, int size)
{
    int pivot = array[high];
    int i = low;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i < j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
            i++;
        }

    }

    if (array[i] > array[high])
    {
        swap(&array[i], &array[high]);
        print_array(array, size);
    }
    return i;
}
void quicksorthelper(int array[], int low, int high, int size)
{
    int pivotindex;

    if (high - low > 0)
    {
        pivotindex = partition(array, low, high, size);

        quicksorthelper(array, low, pivotindex - 1, size);
        quicksorthelper(array, pivotindex + 1, high, size);


    }
}


void quick_sort(int* array, size_t size)
{

if (array == NULL || size < 2)
    return;

quicksorthelper(array, 0, size - 1, size);

}