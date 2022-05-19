#include <stdlib.h>
#include "malloc.h"
#include <stdio.h>

/*
** allocated block looks like this:
** |-------------------|
** | size | data | prev|
** |-------------------|
*/


/*
** get block size
** |-------------------|
** | size | data | prev|
** |-------------------|
**  ^
**  |
** size_t & ~1
*/
size_t get_block_size(block_ptr block)
{
	return ((*(size_t *)block) & ~1);
}

void set_block_size(block_ptr block, size_t size)
{
	int allocated = is_allocated(block);
	*(size_t *)block = size | (allocated & 1);
}

/*
** get block data
** |-------------------|
** | size | data | prev|
** |-------------------|
**         ^
**         |
** block as char * + sizeof(size_t)
*/
void *get_block_data(block_ptr block)
{
	return ((char *)block + sizeof(size_t));
}

/*
** get next block
** |-------------------|
** | size | data | prev|
** |-------------------|
**                      ^
**                      |
** get the block after the block
*/
block_ptr get_next_block(block_ptr block)
{
	return (
		(char *)get_block_data(block)
		+ get_block_size(block)
		+ sizeof(void *));
}

/*
** get previous block
** |-------------------|
** | size | data | prev|
** |-------------------|
**                ^
**                |
** get the block behind prev pointer
*/
block_ptr *get_prev_block(block_ptr block)
{
	return (void **)((char *)get_block_data(block) + get_block_size(block));
}

/*
** get the left child of the block node
** |--------------------------------------------|
** | size | left | right| parent | color | prev |
** |--------------------------------------------|
*/
block_ptr *get_left_child(block_ptr block)
{
	if (is_allocated(block))
	{
		printf("error: get_left_child: block is allocated\n");
		exit(EXIT_FAILURE);
	}
	return (block_ptr *)((char *)block + sizeof(size_t));
}

/*
** get the right child of the block node
** |--------------------------------------------|
** | size | left | right| parent | color | prev |
** |--------------------------------------------|
*/
block_ptr *get_right_child(block_ptr block)
{
	if (is_allocated(block))
	{
		printf("error: get_right_child: block is allocated\n");
		exit(EXIT_FAILURE);
	}
	return (block_ptr *)((char *)block + sizeof(size_t) + sizeof(void *));
}

/*
** get the parent of the block node
** |--------------------------------------------|
** | size | left | right| parent | color | prev |
** |--------------------------------------------|
*/
block_ptr *get_parent(block_ptr block)
{
	if (is_allocated(block))
	{
		printf("error: get_parent: block is allocated\n");
		exit(EXIT_FAILURE);
	}
	return (block_ptr *)((char *)block + sizeof(size_t) + sizeof(void *) * 2);
}

/*
** get the color of the block node
** |--------------------------------------------|
** | size | left | right| parent | color | prev |
** |--------------------------------------------|
*/
int *get_color(block_ptr block)
{
	if (is_allocated(block))
	{
		printf("error: get_color: block is allocated\n");
		exit(EXIT_FAILURE);
	}
	return (int *)((char *)block + sizeof(size_t) + sizeof(void *) * 3);
}

area_ptr get_tiny_area(void *start)
{
	return (start);
}
area_ptr get_small_area(void *start)
{
	return ((char *)start + TINY_CAPACITY);
}

area_ptr get_large_area(void *start)
{
	return ((char *)start + TINY_CAPACITY + SMALL_CAPACITY);
}