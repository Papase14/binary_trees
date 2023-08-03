#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverse a binary tree in level order and
 * apply a given function to each node's value.
 * @tree: A pointer to the root node of the binary tree to be traversed.
 * @func: A pointer to the function to be applied to each node's value.
 *
 * Description: This function traverses a binary tree in level order
 * and applies a given function to each node's value.
 * It starts from the root node and visits each level of the tree from
 * left to right.
 * The function 'func' is called for each node's value at each level.
 *
 * Return: None
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (tree == NULL || func == NULL)
		return;

	maxlevel = binary_tree_height(tree) + 1;

	for (level = 1; level <= maxlevel; level++)
		btlo_helper(tree, func, level);
}

/**
 * btlo_helper - Helper function to traverse a binary tree in level order
 * and apply a given function to each node's value.
 * @tree: A pointer to the root node of the binary tree to be traversed.
 * @func: A pointer to the function to be applied to each node's value.
 * @level: The current level of the binary tree being traversed.
 *
 * Description:
 * This function is a helper function used by the 'binary_tree_levelorder'
 * function to traverse a binary tree in level order.
 * It is a recursive function that visits each level of the tree from left
 * to right.
 * The function 'func' is called for each node's value at each level.
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	if (level == 1)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}

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
