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
	binary_tree_t *parent = node->parent;
	binary_tree_t *grandparent = node->parent->parent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (grandparent->left == parent)
		return (grandparent->right);
	return (grandparent->left);
}
