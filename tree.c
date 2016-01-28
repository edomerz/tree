#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "tree.h"

int TreeIsLeftChild(tree_iter_t current);
int TreeIsRightChild(tree_iter_t current);

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
	tree_iter_t iter = (assert(tree), TreeBegin(tree));
	tree_iter_t next = NULL;
	
	while(!TreeIsSameIter(iter, TreeEnd(tree)))  
	{
		if(TreeIsSameIter(iter, &tree->root)) /* skip root */
		{
			iter = TreeNext(iter);
		}
		next = TreeNext(iter);
		free(iter);
		iter = next;
	}
	
	free(tree);
	
	return;
}

/* returns the root of tree of END if tree is empty*/
tree_iter_t TreeBegin(const tree_t *tree)
{
	tree_iter_t iter = (assert(tree), NULL);
	
	if(TreeIsEmpty(tree))
	{
		return(TreeEnd(tree));
	}
	
	iter = (tree_iter_t)&tree->root;
	while(iter->l)
	{
		iter = iter->l;
	}
	
	return(iter);
}


tree_iter_t TreeEnd(const tree_t *tree)
{
	return((tree_iter_t)&tree->end);
}

void *TreeGetData(tree_iter_t iter)
{
	return(iter->data);
}

size_t TreeSize(const tree_t *tree)
{
	tree_iter_t iter = NULL;
	size_t c = 0;
	
	if(TreeIsEmpty(tree))
	{
		return(c);
	}
	
	iter = TreeBegin(tree);
	while(!TreeIsSameIter(iter, TreeEnd(tree)))
	{
		++c;
		iter = TreeNext(iter);
	}
	
	return(c);
}

int TreeIsEmpty(const tree_t *tree)
{
	return(tree->end.l == NULL);
}
/*
 searches data in tree, 
returns tree_node if found or END 
*/
tree_iter_t TreeFind(const tree_t *tree, const void *seek)
{
	tree_iter_t iter = (assert(tree), &tree->root);
	size_t count = TreeSize(tree);

	for( ; count; --count)
	{
		if(iter->data == seek)
		{
			return(iter);
		}
		
		switch(tree->cmp(seek, iter->data))
			case 1:
				
	}
}

/* insert tree_node to tree*/
/*   returns its tree_node if successful,*/
/*   else END */
tree_iter_t TreeInsert(tree_t *tree, void *data)
{
	tree_iter_t new_node = NULL;
	tree_iter_t iter = NULL;
	size_t count = (assert(tree), TreeSize(tree));
	int cmp = 666;
	
	if(tree->end.l == NULL) /* empty tree */
	{
		tree->root.data = data;
		tree->root.p = &tree->end;
		
		tree->end.l = &tree->root;
		
		return(&tree->root);
	}
	new_node = (tree_iter_t)malloc(sizeof(tree_node));
	assert(new_node);
	new_node->data = data;
	
	iter = TreeBegin(tree);
	
	for( ; count; --count)
	{
		cmp = tree->fp(data, iter->data);
		switch(cmp)
		{
			case -1:
				new_node->p = iter;
				new_node->l = iter->l;
				new_node->r = NULL;
				
				if(!iter->l)
				{
					iter->l = new_node;
					
					return(new_node);
				}
				iter->l->p = new_node;
				iter->l = new_node;
			
				return(new_node);
				break;
			case 0:
			
				new_node->p = iter;
				new_node->l = NULL;
				new_node->r = iter->r;
				
				if(!iter->r)
				{
					iter->r = new_node;
					
					return(new_node);
				}			
				iter->r->p = new_node;
				iter->r = new_node;
			
				return(new_node);
				break;
			
			case 1:
				if(TreeIsSameIter(TreeNext(iter), TreeEnd(tree)))
				{
					new_node->p = iter;
					new_node->l = NULL;
					new_node->r = NULL;
				
					iter->r = new_node;
				
					return(new_node);
				}
				iter = TreeNext(iter);
				
				break;
				
			default:
				return(TreeEnd(tree));	
				break;		
		}
	}
	return(NULL);
}
	

/* removes the tree_node with data, */
/* returns NEXT tree_iter_t with tha DATA or END */
/*void TreeRemove(tree_t *tree, tree_iter_t iter);*/

/* gets the next tree_iter_t  of CURRENT */
tree_iter_t TreeNext(const tree_iter_t current)
{
	tree_iter_t iter = NULL;
	
/*	has right child*/
	if(current->r)
	{
		iter = current->r;
		while(iter->l)
		{
			iter = iter->l;
		}
		return(iter);
	}
	
	if(TreeIsLeftChild(current))
	{
		return(current->p);
	}
	
	while(current->p)
	{
		iter = current->p;
		
		if(TreeIsLeftChild(iter))
		{
			return(iter->p);
		}
	}
	return(NULL);
}

/* gets the prev tree_iter_t  of CURRENT */
tree_iter_t TreePrev(const tree_iter_t current)
{
	tree_iter_t iter = NULL;
	
/*	has left child*/
	if(current->l)
	{
		iter = current->l;
		while(iter->r)
		{
			iter = iter->r;
		}
		return(iter);
	}
	
	if(TreeIsRightChild(current))
	{
		return(current->p);
	}
	
	while(current->p)
	{
		iter = current->p;
		
		if(TreeIsLeftChild(iter))
		{
			return(iter->p);
		}
	}
	return(NULL);
}
/*
 Performs an action deteremined by 'action_func' on each element 
  stops upon action_func failure. 
   returns action_func exit status. 
int TreeForEachr(const tree_iter_t begin, const tree_iter_t end, action_func fp, void *param);

*/  
int TreeIsSameIter(const tree_iter_t iter1, const tree_iter_t iter2)
{
	return(iter1->data == iter2->data);
}


int TreeIsLeftChild(tree_iter_t current)
{
	return(TreeIsSameIter(current, current->p->l));
}

int TreeIsRightChild(tree_iter_t current)
{
	return(TreeIsSameIter(current, current->p->r));
}
