#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes in a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The number of nodes in the binary tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes, right_nodes;

	if (tree == NULL)
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	return (left_nodes + right_nodes + (tree->left != NULL || tree->right != NULL));
}
