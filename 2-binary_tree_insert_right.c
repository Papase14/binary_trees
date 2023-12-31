#include "binary_trees.h"
/**
 * binary_tree_insert_right - Inserts a new node as the right
 * child of a given parent node in a binary tree.
 *
 * @parent: A pointer to the parent node where the new node
 * will be inserted as the right child.
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the newly created node, or NULL if
 * the parent is NULL or the creation of the new node fails.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (parent == NULL)
		return (NULL);

	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	parent->right = new_node;
	return (new_node);
}
