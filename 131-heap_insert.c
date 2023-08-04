#include "binary_trees"


/**
 * heap_insert - Inserts a new node with the given value into a binary heap
 * represented by a binary tree.
 * The function ensures that the binary heap property is maintained
 * after the insertion,
 * which means that the parent node is always greater than or equal
 * to its children nodes.
 *
 * @root: A double pointer to the root node of the binary tree
 * representing the binary heap.
 * @value: The value to be inserted as a new node in the binary heap.
 *
 * Return: A pointer to the new node that has been inserted into the binary heap.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}
	return (new);
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
