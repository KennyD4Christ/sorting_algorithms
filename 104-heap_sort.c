#include "sort.h"

/**
 *  * sift_down - Perform the sift down operation on a heap array
 *   * @array: The array representing the heap
 *    * @size: The size of the array
 *     * @root: The root index of the subtree
 *      * @end: The last index of the array
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
size_t max, left, right;
while ((left = 2 * root + 1) <= end)
{
right = left + 1;
max = (right <= end && array[right] > array[left]) ? right : left;
if (array[root] >= array[max])
break;
/* Swap root with max */
array[root] ^= array[max];
array[max] ^= array[root];
array[root] ^= array[max];
print_array(array, size);
root = max;
}
}

/**
 *  * heapify - Build a heap from the array
 *   * @array: The array to be sorted
 *    * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
size_t start = (size - 2) / 2;
while (start < size)
{
sift_down(array, size, start, size - 1);
if (start == 0)
break;
start--;
}
}

/**
 *  * heap_sort - Sorts an array of integers in ascending order
 *  using the Heap sort algorithm
 *   * @array: The array to be sorted
 *    * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
size_t end;
if (array == NULL || size < 2)
return;
heapify(array, size);
for (end = size - 1; end > 0; end--)
{
/* Swap root with end */
array[0] ^= array[end];
array[end] ^= array[0];
array[0] ^= array[end];
print_array(array, size);
sift_down(array, size, 0, end - 1);
}
}
