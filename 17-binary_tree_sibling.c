#include "binary_trees.h"

/**
 * binary_tree_sibling - Returns the sibling node of a given node in a binary tree.
 * @node: A pointer to a node in a binary tree.
 *
 * Return: A pointer to the sibling node of the input node.
 *         If the input node is NULL or has no parent, return NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
