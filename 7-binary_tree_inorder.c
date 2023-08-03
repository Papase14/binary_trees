#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse a binary tree in inorder
 * and apply a function to each node
 *
 * @tree: A pointer to the root node of the binary tree
 * @func: A pointer to a function that takes an integer
 * as input and returns void
 *
 * Description: This function traverses a binary tree in
 * an inorder manner and applies a given function to each visited node.
 * The function visits the left subtree, then the current
 * node, and then the right subtree.
 *
 * Return: None
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
