#include "sort.h"
#include <stdlib.h>
#include <stdint.h>

/**
 *  * counting - Perform counting sort based on significant digit
 *   * @array: The array to be sorted
 *    * @size: The size of the array
 *     * @exp: The exponent value for the current significant digit
 */
void counting(int *array, size_t size, int exp)
{
int *output = malloc(size * sizeof(int));
int count[10] = {0};
size_t i;
if (output == NULL)
return;
for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;
for (i = 1; i < 10; i++)
count[i] += count[i - 1];
for (i = size - 1; i < SIZE_MAX; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}
for (i = 0; i < size; i++)
array[i] = output[i];
free(output);
}

/**
 *  * radix_sort - Sorts an array of integers in ascending order
 *  using Radix sort algorithm
 *   * @array: The array to be sorted
 *    * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
int max = 0;
size_t i;
int exp;
if (array == NULL || size < 2)
return;
for (i = 0; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
for (exp = 1; max / exp > 0; exp *= 10)
{
counting(array, size, exp);
print_array(array, size);
}
}
