/*
 * File: 16-binary_tree_is_perfect.c
 * Auth: Sess254
 */

#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *obtain_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth,
				size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - checks if node is a leaf
 * @node: pointer to the node to check if its a leaf
 * Return: 1 if its a leaf, 0 if otherwise
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - checks the depth of a node in a binary tree
 * @tree: pointer to the root node to check the depth
 * Return: depth of the node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * obtain_leaf - returns leaf of a binary tree
 * @tree: pointer to the root node to find the leaf in
 * Return: pointer to the leaf
 */
const binary_tree_t *obtain_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? obtain_leaf(tree->left) : obtain_leaf(tree->right));
}

/**
 * is_perfect_recursive - checks if a tree is perfect recursively
 * @tree: pointer to root node
 * @leaf_depth: depth of a leaf in a binary tree
 * @level: level of the node
 * Return: 1 if tree is perfect, 0 if otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t leaf_depth,
				size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(obtain_leaf(tree)), 0));
}
