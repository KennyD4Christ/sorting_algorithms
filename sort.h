#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 *  * struct listint_s - A structure representing a node in a
 *  linked list of integers
 *   *
 *    * @n: Integer stored in the node
 *     * @prev: Pointer to the previous element of the list
 *      * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/* Prototype for print_array function */
void print_array(const int *array, size_t size);

/* Prototype for print_list function */
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *a, int *b);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
int get_max(int *array, int size);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		  size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t root, size_t end);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void counting(int *array, size_t size, int exp);
void bitonic_sort_recursive(int *array, size_t size,
			    size_t low, size_t cnt, int up);
void bitonic_merge(int *array, size_t size, size_t low, size_t cnt, int up);
void bitonic_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
void swap_ints(int *a, int *b);

/**
 *  * enum bool - Enumeration of Boolean values.
 *   * @false: Equals 0.
 *    * @true: Equals 1.
 *     */
typedef enum bool
{
false = 0,
true
} bool;

#endif /* SORT_H */
