/*
 * File: 14-binary_tree_balance.c
 * Auth: Sess254
 */

#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance
 * Return: balance, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_h = 0;
	size_t r_h = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l_h = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			r_h = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((l_h > r_h) ? l_h : r_h);
	}
}
/**
 * binary_tree_balance - measures the balance of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance
 * Return: balance, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;
	int total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height(tree->left));
		right = ((int)binary_tree_height(tree->right));
		total = left - right;
	}
	return (total);
}
