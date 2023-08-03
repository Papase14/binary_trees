#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverse a binary tree in inorder
 * and apply a function to each node.
 *
 * @tree: A pointer to the root node of the binary tree.
 * @func: A pointer to a function that takes an integer
 * as input and returns void.
 *
 * Description: This function traverses a binary tree in an
 * inorder manner and applies the given function to each visited node.
 * The inorder traversal visits the left subtree, then the
 * current node, then the right subtree.
 * If the tree is empty or the function pointer is NULL, the
 * function does nothing.
 *
 * Return: None.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_inorder(tree->left, func);
	binary_tree_inorder(tree->right, func);
}
