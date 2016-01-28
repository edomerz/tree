#include <stdio.h>

#include "tree.h"

int Cmp(const void *data1, const void *data2);

int main(int argc, char* argv[], char** envp)
{
	tree_t *tree = NULL;
/*	int size1 = -9;*/
/*	void *data1 = NULL;*/
	
	/*__________  TreeCreate  __________*/
	printf("\n[%s %s %d]TreeCreate\n", __FILE__, __func__, __LINE__);
	
	tree = TreeCreate(Cmp);

	/*__________  TreeBegin  __________*/
	printf("\n[%s %s %d]TreeBegin\n", __FILE__, __func__, __LINE__);
	
/*	printf("TreeBegin:%p\n", (void*)TreeBegin(tree));*/

	/*__________  TreeEnd  __________*/
	printf("\n[%s %s %d]TreeEnd\n", __FILE__, __func__, __LINE__);
	
	printf("TreeEnd:%p\n", (void*)TreeEnd(tree));
	

	/*__________  TreeGetData  __________*/
/*	printf("\n[%s %s %d]TreeGetData\n", __FILE__, __func__, __LINE__);*/
	
/*	printf("data1:%p\n", data1);*/

	/*__________  TreeSize  __________*/
/*	printf("\n[%s %s %d]TreeSize\n", __FILE__, __func__, __LINE__);*/
	
/*	size1 = TreeSize(tree);*/
/*	printf("size1:%d\n", size1);*/
	/*__________  TreeDestroy  __________*/
	printf("\n%s.%s.%d.TreeDestroy\n", __FILE__, __func__, __LINE__);
	
	TreeDestroy(tree);
	
	return(0);
}

int Cmp(const void *data1, const void *data2)
{
	return(data1 == data2 ? 0 : (data1 < data2 ? -1 : 1));
}
