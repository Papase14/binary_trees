#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverse a binary tree in pre-order
 * and apply a function to each node
 *
 * @tree: A pointer to the root node of the binary tree
 * @func: A pointer to a function that takes an integer as
 * input and returns void
 *
 * Description: This function traverses a binary tree in pre-order
 * and applies a given function to each visited node.
 * The traversal is performed in a pre-order manner, meaning that
 * the function is applied to the current node
 * before its subtrees are visited.
 *
 * Return: None
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
