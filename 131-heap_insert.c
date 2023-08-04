#include "binary_trees"

/**
 * heap_insert - Inserts a new node with the given value into a
 * binaryheap represented by a binary tree.
 * Ensures that the binary heap property is maintained after
 * the insertion.
 *
 * @root: A double pointer to the root node of the binary tree
 * representing the binary heap.
 * @value: The value to be inserted as a new node in the binary heap.
 *
 * Return A pointer to the newly inserted node in the binary heap.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (root == NULL)
		return NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return *root;
	}

	heap_t *tree = *root;
	int size = binary_tree_size(tree);
	int leaves = size, sub = 1, level = 0, bit, tmp;

	while (leaves >= sub)
	{
		leaves -= sub;
		sub *= 2;
		level++;
	}

	bit = 1 << (level - 1);

	while (bit != 1)
	{
		if (leaves & bit)
			tree = tree->right;
		else
			tree = tree->left;
		bit >>= 1;
	}

	heap_t *new = binary_tree_node(tree, value);

	if (leaves & 1)
		tree->right = new;
	else
		tree->left = new;

	heap_t *flip = new;

	while (flip->parent && (flip->n > flip->parent->n))
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		flip = flip->parent;
	}

	return new;
}

/**
 * binary_tree_size - Calculates the size of a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The total number of nodes in the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
