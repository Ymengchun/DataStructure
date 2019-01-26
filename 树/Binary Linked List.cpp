#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h> 									/* 定义OVERFLOW */
#define MAXSIZE 100
#define SIZE 20										/* 结点数 */

int index = 1;
typedef char String[SIZE];							/* 0号单元存放串的长度 */
String str;
typedef char ElemType;
ElemType Nil = ' ';

/* 二叉链表的结构定义 */
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/* 存储串 */
bool StrAssign(String T, char *chars){
	int i;
	
	if(strlen(chars) > MAXSIZE)
		return false;
	else{
		T[0] = strlen(chars);						/* T[0]存储串的长度 */
		for(i = 1; i < T[0]; i++)
			T[i] = *(chars+i-1);
		return true;
	} 
}

/* 初始化 */
bool InitBiTree(BiTree *T){
	*T = NULL;
	return true;
}

/* 销毁 */
void DestroyBiTree(BiTree *T){
	if(*T){
		if((*T)->lchild)							/* 有左孩子 */
			DestroyBiTree(&(*T)->lchild);
		if((*T)->rchild)							/* 有右孩子 */
			DestroyBiTree(&(*T)->rchild);
		free(*T);
		*T = 0;	
	}
} 

/* 清空 */
#define ClearBiTree DestroyBiTree

/* 建立二叉链表(前序输入) */
bool CreateBiTree(BiTree *T){
	ElemType ch;
	
	/* scanf("%c",&ch); */
	ch = str[index++];
	if(ch == '#')
		*T = NULL;
	else{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);		
	}
}

/* 判空 */
bool BiTreeEmpty(BiTree T){
	if(T)
		return false;
	else 
		return true;
}

/* 深度 */
int BiTreeDepth(BiTree T){
	int i, j;
	
	if(!T)
		return 0;
			
	if(T->lchild)									/* 有左孩子 */
		i = BiTreeDepth(T->lchild);
	else 
		i = 0;
		
	if(T->rchild)									/* 有右孩子 */
		j = BiTreeDepth(T->rchild);
	else 
		j = 0;
	
	return i>j ? i+1 : j+1;
}

/* 返回根 */
ElemType Root(BiTree T){
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/* 返回p指向的结点的值 */
ElemType Value(BiTree p){
	return p->data;
}

/* 给p所指的结点赋值为valve */
void Assign(BiTree p, ElemType value){
	p->data = value;
}

/* 前序递归遍历 */
void PreOrderTraverse(BiTree T){
	if(T == NULL)
		return ;
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/* 中序递归遍历 */
void InOrderTraverse(BiTree T){
	if(T == NULL)
		return ;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}

/* 后序递归遍历 */
void PostOrderTraverse(BiTree T){
	if(T == NULL)
		return ;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}






