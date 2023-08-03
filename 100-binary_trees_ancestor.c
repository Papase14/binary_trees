#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor
 * of two nodes in a binary tree.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: The lowest common ancestor of the two input nodes,
 * or NULL if either of the input nodes is NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - Calculates the depth of a node in a binary tree.
 *
 * @tree: A pointer to the node for which the depth needs to be determined.
 *
 * Return: The depth of the given node in the binary tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
