#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *  * bitonic_merge - performs a bitonic merge operation on a
 *  segment of an array
 *   * @array: pointer to the array segment to be merged
 *   @size: Total number of elements in the array
 *    * @low: starting index of the segment to be merged
 *     * @cnt: number of elements in the segment to be merged
 *      * @up: flag indicating the direction of merging
 *      (1 for ascending, 0 for descending)
 *       *
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t cnt, int up)
{
size_t i;
if (cnt > 1)
{
size_t k = cnt / 2;
for (i = low; i < low + k; ++i)
{
if ((array[i] > array[i + k]) == up)
{
int tmp = array[i];
array[i] = array[i + k];
array[i + k] = tmp;
}
}
bitonic_merge(array, size, low, k, up);
bitonic_merge(array, size, low + k, k, up);
}
}

/**
 *  * bitonic_sort_recursive - Recursively sorts a sub-array using
 *  bitonic sort algorithm
 *   *
 *    * @array: Pointer to the array to be sorted
 *     * @size: Total number of elements in the array
 *      * @low: Starting index of the sub-array to be sorted
 *       * @cnt: Number of elements in the sub-array to be sorted
 *   @up: Sorting direction (1 for increasing order, 0 for decreasing order)
 *         *
 */
void bitonic_sort_recursive(int *array, size_t size,
			    size_t low, size_t cnt, int up)
{
if (cnt > 1)
{
size_t k = cnt / 2;
printf("Merging [%lu/%lu] (", cnt, size);
if (up)
printf("UP");
else
printf("DOWN");
printf("):\n");
print_array(&array[low], cnt);
bitonic_sort_recursive(array, size, low, k, 1);
bitonic_sort_recursive(array, size, low + k, k, 0);
bitonic_merge(array, size, low, cnt, up);
printf("Result [%lu/%lu] (", cnt, size);
if (up)
printf("UP");
else
printf("DOWN");
printf("):\n");
print_array(&array[low], cnt);
}
}

/**
 *  * bitonic_sort - Sorts an array of integers in ascending order
 *  using Bitonic sort algorithm
 *   * @array: The array to be sorted
 *    * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
bitonic_sort_recursive(array, size, 0, size, 1);
}
