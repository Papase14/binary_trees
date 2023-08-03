#include "binary_trees.h"

/**
 * binary_tree_balance - Calculates the balance factor of
 * a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The balance factor of the binary tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = (int)binary_tree_height(tree->left);
	int right_height = (int)binary_tree_height(tree->right);

	return (left_height - right_height);
}
