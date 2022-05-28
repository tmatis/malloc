#ifndef RBTREE_H
# define RBTREE_H

#include "../malloc.h"

#define RED 1
#define BLACK 0

typedef struct free_tree_s
{
	block_ptr tiny;
	block_ptr small;
} free_tree_t;

block_ptr get_nil_node(void);
free_tree_t *get_free_trees(void);
block_ptr find_best_fit(size_t size, block_ptr *root);
block_ptr *get_proper_root(size_t size);
void insert_free_block(block_ptr block, block_ptr *root);
void delete_free_block(block_ptr block, block_ptr *root);

#endif //RBTREE_H
