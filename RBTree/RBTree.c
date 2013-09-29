#include "RBTree.h"
#include <stdio.h>
#include <stdlib.h>
#if 0
#include<stdio.h>
#include<stdlib.h>

SqStack InitStack(SqStack S)
{
	S=(SqStack)malloc(sizeof(struct Stack));
	S->base =(struct BiTNode **)malloc(STACK_INIT_SIZE*sizeof(struct BiTNode**));
	if(!S->base) exit(1);
	S->top=S->base;
	S->stacksize =STACK_INIT_SIZE;
	return S;
}

BiTree GetTop(SqStack S)
{
	BiTree e;
	BiTree *p;
	p=S->top;
	if(S->top == S->base) return 0 ;
	p=p-1;
	e=*p;
	return e;

}

SqStack Push(SqStack S,BiTree e)
{
	if((S->top)-(S->base)>=(S->stacksize)){
		S->base =(BiTree*)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(struct BiTNode**));

		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*(S->top)=e;
	S->top++;
	return S;
}


BiTree Pop(SqStack S)
{
	BiTree e;
	if(S->top ==S->base) return NULL;
	S->top=S->top-1;
	e=*S->top;
	return e;
}
int StackEmpty(SqStack S)
{
	if(S==NULL||(S->base == S->top))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



Status CreateBiTree(BiTree *T)
{
	char ch;
	ch=getchar();

	if(ch=='#') (*T)=NULL;
	else
	{
		if(!((*T)=(BiTree)malloc(sizeof(struct BiTNode))))   exit(FALUSE);
		(*T)->data=ch;
		(*T)->lflag = 0;
		(*T)->rflag = 0;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);

	}
	return OK;
}

void PreOrderTraverse(BiTree T)
{
	SqStack S=NULL;
	S=InitStack(S);
	BiTree p=NULL;
	p=T;
	while(p||!StackEmpty(S))
	{
		if(p)
		{
			printf("%4c",p->data);
			S=Push(S,p);
			p=p->lchild;
		}
		else
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
}
void InOrderTraveerse(BiTree T)
{
		SqStack S=NULL;
		S=InitStack(S);
		BiTree p=NULL;
		p=T;
		while(p||!StackEmpty(S))
		{
			if(p){S=Push(S,p); p=p->lchild;}
			else
			{
				p=Pop(S);
				//printf("self: %p, data:%4c, parent:%p, lchild: %p, rchild: %p, High:%d\n", p, p->data, p->parent, p->lchild, p->rchild, p->High);
				printf("%c:%d  ", p->data, p->High);
				
				p=p->rchild;
			}
		}
}
//
void PostOrderTravaerse(BiTree T)
{
	SqStack S=NULL;
	S=InitStack(S);
	BiTree p=NULL;
	BiTree tmp = NULL;
	p = T;
  Push(S, p);
	while(!StackEmpty(S))
	{

		while(p){
			if(p->lflag != 1 )
			{
				if(GetTop(S) != p) {
					Push(S, p);	
				}
				p->lflag = 1;
				if(p->lchild){
                    Push(S, p->lchild);
                    p = p->lchild;
				}
			}else if(p->rflag != 1 )
			{
				if(GetTop(S) != p) {
					Push(S, p);	
				}
				p->rflag = 1;
                if(p->rchild){
                    Push(S, p->rchild);
                    p = p->rchild;
                }

			}
			if(p->lflag == 1 && p->rflag == 1){
                break;
			}
		}
		p = Pop(S);
		//printf("self: %p, data:%4c, parent:%p, lchild: %p, rchild: %p, High:%d\n", p, p->data, p->parent, p->lchild, p->rchild, p->High);
		printf("%c:%d  ", p->data, p->High);
		if(StackEmpty(S)) {
			return;
		}
		tmp = GetTop(S);
		if(tmp->lflag == 1 && tmp->rflag == 1) {
			p = tmp;
		}else if(tmp->lflag != 1){
			tmp->lflag = 1;
			p = tmp->lchild;
		}else if(tmp->rflag != 1){
			tmp->rflag = 1;
			p = tmp->rchild;
		}
	}
}

#endif

static rb_node_t *rb_new_node(key_t key, data_t data)
{
	rb_node_t *node = (rb_node_t *)malloc(sizeof(struct rb_node_t));
	
	if (!node) {
		printf("malloc error!\n");
		exit(-1);
	}
	
	node->key = key;
	node->data = data;
	return node;
}

static rb_node_t *rb_insert_rebalance(rb_node_t *node, rb_node_t *root);
static rb_node_t *rb_erase_rebalance(rb_node_t *node, rb_node_t *parent, rb_node_t *root);
static rb_node_t *rb_rotate_left(rb_node_t *node, rb_node_t *root)
{
	rb_node_t *right = node->right;

	if ((node->right = right->left)) {
		right->left->parent = node;
	}
	
	right->left = node;
	
	if ((right->parent = node->parent)) {
		if (node == node->parent->right) {
			node->parent->right = right;
		}else {
			node->parent->left = right;	
		}
	}else {
		root = right;
	}
	
	node->parent = right;
	
	return root;
}


static rb_node_t *rb_rotate_right(rb_node_t *node, rb_node_t *root)
{
	rb_node_t *left = node->left;
	
	if ((node->left = left->right)) {
		left->right->parent = node;
	}

	left->right = node;
	
	if ((left->parent = node->parent)) {
		if (node == node->parent->right) {
			node->parent->right = left;
		}else {
			node->parent->left = left;
		}
	}else {
		root = left;
	}

	node->parent = left;
	
	return root;
}


static rb_node_t *rb_search_auxiliary(key_t key, rb_node_t *root, rb_node_t **save)
{
	rb_node_t *node = root;
	rb_node_t *parent = NULL;
	int ret = 0;
	
	while(node) {
		parent = node;
		ret = node->key - key;
		
		if(0 < ret) {
			node = node->left;
		} else if (0 > ret) {
			node = node->right;
		}else {
			return node;
		}
	}

	if (save) {
		*save = parent;
	}

	return NULL;
}

rb_node_t *rb_search(key_t key, rb_node_t *root)
{
	return rb_search_auxiliary(key, root, NULL);
}

rb_node_t *rb_insert(key_t key, data_t data, rb_node_t *root)
{
	rb_node_t *parent = NULL;
	rb_node_t *node = NULL;

	parent = NULL;

	if ((node = rb_search_auxiliary(key, root, &parent))) {
		return root;
	}

	node = rb_new_node(key, data);
	node->parent = parent;
	node->left = node->right = NULL;
	node->color = RED;

	if(parent) {
		if (parent->key > key) {
			parent->left = node;
		}else {
			parent->right = node;
		}
	}else {
		root = node;
	}
	return rb_insert_rebalance(node, root);
}

/*
	用z表示当前节点，p[z]表示父节点，p[p[z]]表示祖父节点,y表示叔叔
*/
static rb_node_t *rb_insert_rebalance(rb_node_t *node, rb_node_t *root)
{
	rb_node_t *parent;//父节点p[z]
	rb_node_t *gparent;//祖父节点p[p[z]]
	rb_node_t *uncle;//叔叔节点y
	rb_node_t *tmp;//临时节点
	
	while ((parent = node->parent) && parent->color == RED) {
		//parent 为node的父节点，且当父节点颜色为红 ?不该判断父节点是否为空（根节点）
		gparent = parent->parent;
		
		if (parent == gparent->left) { //当祖父的左孩子即为父母时
			uncle = gparent->right;//定义叔叔的概念 ,叔叔就是父母的右孩子

			if (uncle && uncle->color == RED) {//情况1:z的叔叔y是红色的
				uncle->color = BLACK;//将叔叔节点y染黑
				parent->color = BLACK;//z的父母p[z]染黑，解决z,p[z]都是红色的问题
				gparent->color = RED;

				node = gparent; //将祖父当作新增节点z，指针z上移两层，且染红
			//上述情况1中，只考虑了z作为父母的右孩子的情况
			}else { //情况2：z的叔叔y是黑色的
				if (parent->right == node) { //且z为右孩子
					root = rb_rotate_left(parent, root); // 左旋[节点z，与父母节点]
					tmp = parent;
					parent = node;
					node = tmp; //parent与node互换角色
				}
				//情况3：z的叔叔y是黑色的，此时z成了左孩子
				//注意：1.情况3是由上述情况2变化而来的
				//2：z的叔叔总是黑色的，否则就是情况1了
				//z的父母p[z]染黑
				//原祖父节点染红
				//
				parent->color = BLACK;
				gparent->color = RED;
				root = rb_rotate_right(gparent, root);//右旋[节点z，与祖父节点]
			}
		}else { //当祖父的右孩子是父母时
			uncle = gparent->left;//祖父的左孩子作为叔叔的几点
			if (uncle && uncle->color == RED) {//情况1：z的叔叔y是红色的 
				uncle->color = BLACK;	
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;//同上
			}else {//情况2：z的叔叔y是黑色的
				if (parent->left == node) { //且z为左孩子
					root = rb_rotate_right(parent, root);//以节点parent，root右旋
					tmp = parent;
					parent = node;
					node = tmp;//parent与node互换角色
				}
				//经过情况2的变化，成了情况3
				parent->color = BLACK;
				gparent->color = RED;
				root = rb_rotate_left(gparent, root); //以节点gparent和root右旋
			}
		}
	}
	//当父亲节点为黑色的时候，红黑树的性质不变
	root->color = BLACK;//根节点，不论怎样，都得置为黑色
	return root; //返回根节点
}

rb_node_t *rb_erase(key_t key, rb_node_t *root)
{
	rb_node_t *child;	
	rb_node_t *parent;
	rb_node_t *old;
	rb_node_t *left;
	rb_node_t *node;

	color_t color;

	if (!(node = rb_search_auxiliary(key, root, NULL))) {
		printf("key %d is not exist !/n");
		return root;
	}		

	old = node;
	
	if (node->left && node->right) {
		node = node->right;
		while ((left = node->left) != NULL) {
			node = left;
		}

		child = node->right;
		parent = node->parent;
		color = node->color;

		if (child) {
			child->parent = parent;
		}

		if (parent) {
			if (parent->left == node) {
				parent->left = child;
			}else {
				parent->right = child;
			}
		}else {
			root = child;
		}

		if (node->parent == old) {
			parent = node;
		}

		node->parent = old->parent;
		node->color = old->color;
		node->right = old->right;
		node->left = old->left;

		if (old->parent) {
			if (old->parent->left == old) {
				old->parent->left = node;
			}else {
				old->parent->right = node;
			}
		}else {
			root = node;
		}
		
		old->left->parent = node;

		if (old->right) {
			old->right->parent = node;
		}
	}else {
		if (!node->left) {
			child = node->right;
		}else if (!node->right) {
			child = node->left;
		}

		parent = node->parent;
		color = node->color;

		if (child) {
			child->parent = parent;
		}
	
		if (parent) {
			if (parent->left == node) {
				parent->left = child;
			}else {
				parent->right = child;
			}
		}else {
			root = child;
		}
	}
	
	if (color == BLACK) {
		root = rb_erase_rebalance(child, parent, root);
	}

	return root;
}
//红黑树修复删除的4中情况
//x表示要删除的节点，*other， w表示兄弟节点
static rb_node_t *rb_erase_rebalance(rb_node_t *node, rb_node_t *parent, rb_node_t *root)
{
	rb_node_t *other; //x的兄弟other
	rb_node_t *o_left; //兄弟的左孩子
	rb_node_t *o_right; //兄弟的右孩子
	while ((!node || node->color == BLACK) && node != root) {
		if (parent->left == node) {
			other = parent->right;
			if (other->color == RED) { //情况1：x的兄弟w是红色的
				other->color = BLACK;
				parent->color = RED;//改变颜色 w->黑色
				root = rb_rotate_left(parent, root);
				other = parent->right;
			}

			if ((!other->left || other->left->color == BLACK) &&
						(!other->right || other->right->color == BLACK)) {
				other->color = RED;
				node = parent;
				parent = node->parent;
			}else {
				if (!other->right ||  other->right->color == BLACK) {
					if ((o_left = other->left)) {
						o_left->color = BLACK;
					}

					other->color = RED;
					root = rb_rotate_right(other, root);
					other = parent->right;
				}
				
				other->color = parent->color;
				parent->color = BLACK;
				if (other->right) {
					other->right->color = BLACK;
				}

				root = rb_rotate_left(parent, root);
				node = root;
				break;
			}
		}else {
			other = parent->left;
			if (other->color = RED) {
				other->color = BLACK;
				parent->color = RED;
				root = rb_rotate_right(parent, root);
				other = parent->left;
			}
			
			if ((!other->left || other->left->color == BLACK) && 
					(!other->right || other->right->color == BLACK)) {
				other->color = RED;
				node = parent;
				parent = node->parent;
			}else {
				if (!other->left || other->left->color == BLACK) {
					if ((o_right = other->right)) {
						o_right->color = BLACK;
					}
					other->color = RED;
					root = rb_rotate_left(other, root);
					other = parent->left;
				}
			
				other->color = parent->color;
				parent->color = BLACK;

				if (other->left) {
					other->left->color = BLACK;
				}

				root = rb_rotate_right(parent, root);
				node = root;
				break;
			}
		}
	}
	
	if (node) {
		node->color = BLACK;
	}
	return root;
}