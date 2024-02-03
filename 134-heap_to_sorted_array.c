#include "binary_trees.h"

/**
 * count_h_nodes - counts the number of nodes inside a tree
 * @root: pointer to tree's root node
 *
 * Return: number of tree nodes
 */
int count_h_nodes(binary_tree_t *root)
{
if (!root)
return (0);

return (1 + count_h_nodes(root->left) +
    count_h_nodes(root->right));
}

/**
 * heap_to_sorted_array - creates a sorted array from a max heap
 * @heap: pointer to heap's node
 * @size: pointer to arrays size
 *
 * Return: pointer to array of integeres
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
int i, nodes, *arr = NULL;

*size = 0;
if (!heap)
return (NULL);

nodes = count_h_nodes(heap);
arr = malloc(sizeof(*arr) * nodes);
if (!arr)
return (NULL);

*size = nodes;
for (i = 0; i < nodes; i++)
arr[i] = heap_extract(&heap);

return (arr);
}
