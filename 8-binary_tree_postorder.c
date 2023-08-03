#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree in
 * postorder and apply a function to each node
 *
 * @tree: A pointer to the root node of the binary tree
 * @func: A pointer to a function that takes an integer
 * as argument and returns void
 *
 * Description: This function traverses a binary tree in
 * postorder and applies a given function to each node.
 * Postorder traversal visits the left subtree, then the
 * right subtree, and finally the root node.
 * The function 'func' is applied to the value of each node.
 *
 * Return: None
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
	func(tree->n);
}
