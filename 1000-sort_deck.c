#include "deck.h"
#include <stdlib.h>

/**
 *  * compare_cards - Compare two deck nodes by suit and card value.
 *   * @a: Pointer to the first deck node.
 *    * @b: Pointer to the second deck node.
 *     *
 *      * Return: Negative value if a should be placed before b,
 *       *         positive value if a should be placed after b,
 *        *         0 if a and b are equal.
 */
int compare_cards(const void *a, const void *b)
{
const deck_node_t *node_a = *(const deck_node_t **)a;
const deck_node_t *node_b = *(const deck_node_t **)b;
if (node_a->card->kind != node_b->card->kind)
{
return (node_a->card->kind - node_b->card->kind);
}
if (node_a->card->value[0] == 'A')
return (-1);
if (node_b->card->value[0] == 'A')
return (1);
if (node_a->card->value[0] == 'K')
return (1);
if (node_b->card->value[0] == 'K')
return (-1);
if (node_a->card->value[0] == 'Q')
return (1);
if (node_b->card->value[0] == 'Q')
return (-1);
if (node_a->card->value[0] == 'J')
return (1);
if (node_b->card->value[0] == 'J')
return (-1);
return (atoi(node_a->card->value) - atoi(node_b->card->value));
}

/**
 *  * sort_deck - Sorts a deck of cards in ascending order by
 *  suit and card value.
 *   * @deck: Pointer to a pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
deck_node_t **arr;
int i;
int count = 0;
deck_node_t *current = *deck;
while (current)
{
count++;
current = current->next;
}
arr = malloc(count *sizeof(deck_node_t *));
if (!arr)
return;
current = *deck;
for (i = 0; i < count; i++)
{
arr[i] = current;
current = current->next;
}
qsort(arr, count, sizeof(deck_node_t *), compare_cards);
for (i = 0; i < count - 1; i++)
{
arr[i]->next = arr[i + 1];
arr[i + 1]->prev = arr[i];
}
arr[0]->prev = NULL;
arr[count - 1]->next = NULL;
*deck = arr[0];
free(arr);
}
