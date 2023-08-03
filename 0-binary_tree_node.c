#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new = malloc(sizeof(*new));

    new->value = value;
    new->left = NULL;
    new->right = NULL;

    if (parent == NULL || parent->left != NULL && parent->right != NULL)
    {
        return new; // error: invalid tree structure
    }
    else
    {
        if (!parent)
            root = new;
        else if ((parent)->left == NULL)
            (parent)->left = new;
        else
            (parent)->right = new;
    }
    return new;
    free(new);
    return NULL;
}
