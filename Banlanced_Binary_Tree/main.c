#include <stdio.h>
#include "Banlanced_Binary_Tree.h"
int main(int argc, char *argv[])
{
	BiTree T = NULL;
//#if 0
	Banlanced_Binary_Tree_insert(&T, 'a');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'b');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'c');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'd');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'e');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'f');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'g');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'h');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'i');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'j');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'k');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'l');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'm');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'n');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'o');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'p');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'q');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'r');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 's');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 't');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'u');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'v');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'w');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'x');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'y');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'z');
	InOrderTraveerse(T);	
#if 0
	printf("\n---------------------Insert done!-------------------------------------\n");
	printf("\n---------------------Now delete--------------------------------------\n");
	Banlanced_Binary_Tree_delete(&T, 'f');
	InOrderTraveerse(T);	
	printf("\n----------------------------------------------------------------------\n");
#endif
//#endif
#if 0
	Banlanced_Binary_Tree_insert(&T, 'a');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'b');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'c');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'd');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'e');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'f');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'g');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'h');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'i');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'j');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'k');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'l');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'm');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'n');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'o');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'p');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'q');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'r');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 's');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 't');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'u');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'v');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'w');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'x');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'y');
	//PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
	Banlanced_Binary_Tree_insert(&T, 'z');
	PostOrderTravaerse(T);
	printf("\n----------------------------------------------------------------------\n");
#endif
}
