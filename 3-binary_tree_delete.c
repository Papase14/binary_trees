#include "binary_trees.h"
/**
 * Deletes a binary tree by recursively deleting all its nodes.
 *
 * @param tree A pointer to the root node of the binary tree
 * to be deleted.
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
