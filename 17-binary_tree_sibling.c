/*
 * File: 17-binary_tree_sibling.c
 * Auth: Sess254
 */

#include "binary_trees.h"

/**
 * binary_tree_sibling - finds siblings of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to sibling node, NULL if node is NULL or has no siblings
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
