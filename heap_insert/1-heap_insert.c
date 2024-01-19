#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: a double pointer to the root node of the Heap
 * @value: the value to store in the inserted node
 *
 * Return: pointer to the newly inserted node, or NULL if failed
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t level = 0, tree_height = 0;
	heap_t *location = NULL, *new_node = NULL;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		new_node = binary_tree_node(*root, value);
		*root = new_node;
		return (new_node);
	}

	tree_height = height(*root);

	for (level = 0; level < tree_height; level++)
	{
		location = find_location(*root, level);
		if (location != NULL)
			break;
	}

	new_node = binary_tree_node(location, value);

	if (!location->left)
		location->left = new_node;
	else
		location->right = new_node;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		new_node = swap(root, new_node);
	}

	return (new_node);
}

/**
 * height - finds the height of completed binary tree
 * @root: pointer to the root node of the tree
 *
 * Return: returns the height of the overall tree
 */
size_t height(heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + height(root->left));
}

/**
 * find_location - finds first location that does not have a right child
 * @root: pointer to the root node of the tree
 * @level: keeps track of the current level in the tree
 *
 * Return: location to insert new node off of, or NULL if has two children
 */
heap_t *find_location(heap_t *root, size_t level)
{
	heap_t *location = NULL;

	if (root == NULL)
		return (NULL);

	if (level == 0 && root->right == NULL)
		return (root);

	else if (level == 0)
		return (NULL);

	location = find_location(root->left, level - 1);

	if (location != NULL)
		return (location);

	location = find_location(root->right, level - 1);

	return (location);
}

/**
 * swap - swaps the new node with its parent
 * @root: double pointer to the root node of the max binary heap
 * @new: recently inserted node to swap
 *
 * Return: pointer to new node after switch
 */
heap_t *swap(heap_t **root, heap_t *new_node)
{
	int left = 0;
	heap_t *temp = new_node->parent, *temp_r = temp->right, *temp_l = temp->left;

	if (new_node->parent->left == new_node)
		left = 1;

	new_node->parent->right = new_node->right;

	if (new_node->right)
		new_node->right->parent = new_node->parent;

	new_node->parent->left = new_node->left;

	if (new_node->left)
		new_node->left->parent = new_node->parent;

	if (left)
	{
		new_node->right = temp_r;
		if (temp_r)
			temp_r->parent = new_node;
	}
	else
	{
		new_node->left = temp_l;
		if (temp_l)
			temp_l->parent = new_node;
	}

	new_node->parent = temp->parent;

	if (temp->parent)
	{
		if (temp->parent->left == temp)
			temp->parent->left = new_node;
		else
			temp->parent->right = new_node;
	}
	else
		*root = new_node;

	if (left)
		new_node->left = temp;
	else
		new_node->right = temp;

	temp->parent = new_node;

	return (new_node);
}
