/*
	tree
*/
	
#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>

typedef struct tree_node *tree_iter_t;
typedef struct tree_adt tree_t;

typedef int (*cmp) (const void *data1, const void *data2);
typedef int(*action_func)(void *data, void *param);

tree_t *TreeCreate(cmp fp);

void TreeDestroy(tree_t *tree);

/* returns a ptr to the begining of the tree */
tree_iter_t TreeBegin(const tree_t *tree);

/* returns a pointer to the end of the tree */
tree_iter_t TreeEnd(const tree_t *tree);

void *TreeGetData(tree_iter_t iter);

size_t TreeSize(const tree_t *tree);

int TreeIsEmpty(const tree_t *tree);

/* searches data in tree, 
returns tree_node if found or END */
tree_iter_t TreeFind(const tree_t *tree, const void *seek);

/* insert tree_node to tree
   returns its tree_node is successful,
   else END */
tree_iter_t TreeInsert(tree_t *tree, void *data);

/* removes the tree_node with data, 
 returns NEXT tree_iter_t with tha DATA or END */
void TreeRemove(tree_t *tree, tree_iter_t iter);

/* gets the next tree_iter_t  of CURRENT */
tree_iter_t TreeNext(const tree_iter_t current);
/* gets the prev tree_iter_t  of CURRENT */
tree_iter_t TreePrev(const tree_iter_t current);

/* Performs an action deteremined by 'action_func' on each element 
  stops upon action_func failure. 
   returns action_func exit status. */
int TreeForEach(const tree_iter_t begin, const tree_iter_t end, action_func fp, void *param);

 /*  */
int TreeIsSameIter(const tree_iter_t iter1, const tree_iter_t iter2);
	
#endif /* ifndef __TREE_H__*/
