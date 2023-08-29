/*
 * File: 2-binary_tree_insert_right.c
 * Auth: Sess254
 */

#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as right child of another node
 * @parent: pointer to the node to insert right child to
 * @value: value to store in new node
 * Return: pointer to new node, NULL if parent is NULL or failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}

	if (parent != NULL)
	{
		if (parent->right != NULL)
		{
			parent->right->parent = new_node;
			new_node->right = parent->right;
		}
		parent->right = new_node;
	}

	return (new_node);
}
