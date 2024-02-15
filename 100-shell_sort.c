#include "sort.h"

/**
 *  * shell_sort - Sorts an array of integers in ascending order
 *   *              using Shell sort algorithm with Knuth sequence
 *    * @array: The array to be sorted
 *     * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
size_t gap = 1, i, j;
int temp;

/* Calculate initial gap using Knuth sequence */
while (gap < size / 3)
gap = gap * 3 + 1;

/* Start with the largest gap and work towards smaller gaps */
while (gap > 0)
{
/* Perform insertion sort for elements at intervals of gap */
for (i = gap; i < size; i++)
{
temp = array[i];
j = i;

/* Move elements of array[0..i-gap], array[0..i-2*gap], ... */
while (j >= gap && array[j - gap] > temp)
{
array[j] = array[j - gap];
j -= gap;
}
array[j] = temp;
}

/* Decrease the gap */
gap = (gap - 1) / 3;

/* Print array after decreasing the interval */
print_array(array, size);
}
}
