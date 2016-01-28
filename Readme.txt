binary tree

struct binary_tree
{
	void *data
	binary_tree *left; 	// left->data < root->data
	binary_tree *right;//  right->data >= root->data (or > if no duplicates are allowed)
}


leaf - node without sons; 
 
 what is 'END' , 'NEXT', 'PREV'  in a tree struct ?
 
 
PRE, IN, POST order - name for traversing the tree;
