
#include"BiTree.h"
#include<stdlib.h>
#include<stdio.h>

int main()
{
	BiTree root=NULL;
	printf("Create BiTree..\n");
	CreateBiTree(&root);
	printf("\nDone!!!!\n");

	printf("PreOrderTraverse..\n");
	PreOrderTraverse( root);
	printf("\nDone!!!!\n");

	printf("InOrderTraveerse..\n");
 	InOrderTraveerse(root);
	printf("\nDone!!!!\n");

	printf("�������.....\n");
  PostOrderTravaerse(root);
	printf("\n�������\n");

	return 0;	
}
