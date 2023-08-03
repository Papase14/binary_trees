#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree as a size_t value.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((left_height > right_height) ? left_height : right_height);
}

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
