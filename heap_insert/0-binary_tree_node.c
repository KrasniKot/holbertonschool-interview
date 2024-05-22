#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: is a pointer to the parent node of the node to create.
 * @value: is the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nn = malloc(sizeof(binary_tree_t));  // Create the space that a binary_tree_t occupies

	if (!nn)  // Return null if couldn't be created
		return (NULL);

	/* Setting values for: left and right nodes; n (integer it holds) and parent */
	nn->left = nn->right = NULL;
	nn->n = value;
	nn->parent = parent;

	return (nn);
}
