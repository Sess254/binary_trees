/*
 * File: 18-binary_tree_uncle.c
 * Auth: Sess254
 */

#include "binary_trees.h"

/**
 * binary_tree_uncle - find the uncle of a node
 * @node: pointer to the node to find it uncle
 * Return: pointer to uncle node, NULL if node is NULL or has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
