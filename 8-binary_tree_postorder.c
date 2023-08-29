/*
 * File: 8-binary_tree_postorder.c
 * Auth: Sess254
 */

#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a tree using post traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to the function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
