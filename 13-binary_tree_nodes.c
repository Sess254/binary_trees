/*
 * File: 13-binary_tree_nodes.c
 * Auth: Sess254
 */

#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at leats 1 child
 * @tree: pointer to the root node of the binary tree to count the nodes
 * Return: number of nodes, 0 if the tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left != NULL || tree->right != NULL)
	{
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	}
	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
