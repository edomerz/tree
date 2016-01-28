#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "tree.h"

typedef struct tree_node
{
	void *data;
	struct tree_node *r;
	struct tree_node *l;
	struct tree_node *p;
}tree_node;

typedef struct tree_adt
{
	tree_node root;
	tree_node end;
	cmp fp;
}tree_adt;

tree_t *TreeCreate(cmp fp)
{
	tree_t *t = (tree_t*)malloc(sizeof(tree_t));
	assert(t);
	
	t->fp = fp;
	
	t->end.data = NULL;
	t->end.r = NULL;
	t->end.l = NULL;
	t->end.p = NULL;
	
	t->root.data = NULL;
	t->root.r = NULL;
	t->root.l = NULL;
	t->root.p  = NULL;
	
	return(t);
}

void TreeDestroy(tree_t *tree)
{
	free(tree);
	
	return;
}

/* returns the root of tree of END if tree is empty*/
tree_iter_t TreeBegin(const tree_t *tree)
{
	if(TreeIsEmpty(tree))
	{
		return(TreeEnd(tree));
	}
	
	return((tree_iter_t)&tree->root);
}


tree_iter_t TreeEnd(const tree_t *tree)
{
	return((tree_iter_t)&tree->end);
}

void *TreeGetData(tree_iter_t iter)
{
	return(iter->data);
}
/*
size_t TreeSize(const tree_t *tree);
*/
int TreeIsEmpty(const tree_t *tree)
{
/*	to do */
	return(666);
}
/*
 searches data in tree, 
returns tree_node if found or END 
tree_iter_t TreeFind(const tree_t *tree, const void *seek);

 insert tree_node to tree
   returns its tree_node is successful,
   else END 
tree_iter_t TreeInsert(tree_t *tree, void *data);

 removes the tree_node with data, 
 returns NEXT tree_iter_t with tha DATA or END 
void TreeRemove(tree_t *tree, tree_iter_t iter);

 gets the next tree_iter_t  of CURRENT 
tree_iter_t TreeNext(const tree_iter_t current);
 gets the prev tree_iter_t  of CURRENT 
tree_iter_t TreePrev(const tree_iter_t current);

 Performs an action deteremined by 'action_func' on each element 
  stops upon action_func failure. 
   returns action_func exit status. 
int TreeForEach(const tree_iter_t begin, const tree_iter_t end, action_func fp, void *param);

   
int TreeIsSameIter(const tree_iter_t iter1, const tree_iter_t iter2);
*/
