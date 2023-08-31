/*
 * File: 15-binary_tree_is_full.c
 * Auth: Sess254
 */

#include "binary_trees.h"

int is_full_recursive(const binary_tree_t *tree);
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check if its full
 * Return: if NULL 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_full_recursive(tree));

}

/**
 * is_full_recursive - checks if a binary tree is full recursively
 * @tree: pointer to the root node of the tree to check if its full
 * Return: if tree is not full, 1 otherwise
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left == NULL && tree->right != NULL) ||
			(tree->left != NULL && tree->right == NULL) ||
			is_full_recursive(tree->left) == 0 ||
			is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

