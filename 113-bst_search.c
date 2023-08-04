#include "binary_trees.h"

/**
 * bst_search - Search for a specific value in a binary search tree
 * @tree: A pointer to the root node of the binary search tree
 * @value: The value to be searched for in the binary search tree
 *
 * Return: A pointer to the node containing the value, or
 * NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (tree == NULL)
		return (0);

	while (node)
	{
		if (value == node->n)
			return (node);
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
	}

	return (NULL);
}