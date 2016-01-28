#include <stdio.h>

#include "tree.h"

int Cmp(const void *data1, const void *data2);

int main(int argc, char* argv[], char** envp)
{
	tree_t *tree = NULL;
	
	tree_iter_t node1 = NULL;
	int n1 = 20;
	void *data1 = (void*)&n1;
	int ret_n1 = 666;
	
	tree_iter_t node2 = NULL;
	int n2 = 9;
	void *data2 = (void*)&n2;
	int ret_n2 = 666;

	tree_iter_t node3 = NULL;
	int n3 = 22;
	void *data3 = (void*)&n3;
	int ret_n3 = 666;
	
	size_t size = 666;
	
	
	/*__________  TreeCreate  __________*/
	printf("\n[%s %s %d]TreeCreate\n", __FILE__, __func__, __LINE__);
	
	tree = TreeCreate(Cmp);

	/*__________  TreeBegin  __________*/
	printf("\n[%s %s %d]TreeBegin\n", __FILE__, __func__, __LINE__);
	
	printf("TreeBegin:%p\n", (void*)TreeBegin(tree));

	/*__________  TreeEnd  __________*/
	printf("\n[%s %s %d]TreeEnd\n", __FILE__, __func__, __LINE__);
	
	printf("TreeEnd:%p\n", (void*)TreeEnd(tree));

	/*__________  TreeIsEmpty_1  __________*/
	printf("\n[%s %s %d]TreeIsEmpty_1\n", __FILE__, __func__, __LINE__);
	
	printf("TreeIsEmpty_1:%d\n", TreeIsEmpty(tree));	
	
	/*__________  TreeInsert 1  __________*/
	printf("\n[%s %s %d]TreeInsert_1\n", __FILE__, __func__, __LINE__);
	
	node1 = TreeInsert(tree, data1);
	printf("node1:%p\n", (void*)node1);

	/*__________  TreeGetData  __________*/
	printf("\n[%s %s %d]TreeGetData\n", __FILE__, __func__, __LINE__);
	
	ret_n1 = *(int*)TreeGetData(node1);
	printf("ret_n1:%d\n", ret_n1);

	/*__________  TreeSize 1 __________*/
	printf("\n[%s %s %d]TreeSize 1\n", __FILE__, __func__, __LINE__);
	
	size = TreeSize(tree);
	printf("size:%lu\n", size);
	
	/*__________  TreeInsert 2  __________*/
	printf("\n[%s %s %d]TreeInsert_2\n", __FILE__, __func__, __LINE__);
	
	node2 = TreeInsert(tree, data2);
	printf("node2:%p\n", (void*)node2);

	/*__________  TreeGetData 2 __________*/
	printf("\n[%s %s %d]TreeGetData 2\n", __FILE__, __func__, __LINE__);
	
	ret_n2 = *(int*)TreeGetData(node2);
	printf("ret_n2:%d\n", ret_n2);

	/*__________  TreeSize 2 __________*/
	printf("\n[%s %s %d]TreeSize 2\n", __FILE__, __func__, __LINE__);
	
	size = TreeSize(tree);
	printf("size2:%lu\n", size);
	
	
	/*__________  TreeInsert 3  __________*/
	printf("\n[%s %s %d]TreeInsert_3\n", __FILE__, __func__, __LINE__);
	
	node3 = TreeInsert(tree, data3);
	printf("node3:%p\n", (void*)node3);

	/*__________  TreeGetData 3 __________*/
	printf("\n[%s %s %d]TreeGetData 3\n", __FILE__, __func__, __LINE__);
	
	ret_n3 = *(int*)TreeGetData(node3);
	printf("ret_n3:%d\n", ret_n3);

	/*__________  TreeSize 3 __________*/
	printf("\n[%s %s %d]TreeSize 3\n", __FILE__, __func__, __LINE__);
	
	size = TreeSize(tree);
	printf("size3:%lu\n", size);
	
	
	/*__________  TreeNext 1 __________*/
	printf("\n[%s %s %d]TreeNext 1\n", __FILE__, __func__, __LINE__);
	
	printf("next of biggest num node3  :%p		expected result end:%p\n", (void*)TreeNext(node3), (void*)TreeEnd(tree));
	
	printf("prev of smallest num node 2:%p		expected result end:%p\n", (void*)TreePrev(node2), (void*)TreeEnd(tree));
	
	printf("next of node1              :%p   expected result node 3:%p\n", (void*)TreeNext(node1), (void*)node3);
	printf("prev of node1              :%p    expected result node2:%p\n", (void*)TreePrev(node1), (void*)node2);	
	
	
	
		
	/*__________  TreeDestroy  __________*/
	printf("\n%s.%s.%d.TreeDestroy\n", __FILE__, __func__, __LINE__);
	
	TreeDestroy(tree);
	
	return(0);
}

int Cmp(const void *data1, const void *data2)
{
	return(*(int*)data1 == *(int*)data2 ? 0 : (*(int*)data1 < *(int*)data2 ? -1 : 1));
}
