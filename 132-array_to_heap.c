#include "binary_trees.h"

/**
 * array_to_heap - Create a binary heap from an array of integers
 * @array: Pointer to an array of integers
 * @size: Size of the array
 *
 * Return: Pointer to the root of the binary heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *heap = (heap_t *)malloc(sizeof(heap_t));
	heap->root = NULL;

	for (size_t i = 0; i < size; i++)
	{
		heap->root = heap_insert(heap->root, array[i]);
	}

	return heap;
}
