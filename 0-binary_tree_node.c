#include "binary_trees.h"
/**
 * binary_tree_node - Creates a new node for a binary tree.
 * @parent: A pointer to the parent node of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: A pointer to the newly created node,
 * or NULL if the allocation failed.
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
