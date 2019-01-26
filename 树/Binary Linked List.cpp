#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h> 									/* ����OVERFLOW */
#define MAXSIZE 100
#define SIZE 20										/* ����� */

int index = 1;
typedef char String[SIZE];							/* 0�ŵ�Ԫ��Ŵ��ĳ��� */
String str;
typedef char ElemType;
ElemType Nil = ' ';

/* ��������Ľṹ���� */
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/* �洢�� */
bool StrAssign(String T, char *chars){
	int i;
	
	if(strlen(chars) > MAXSIZE)
		return false;
	else{
		T[0] = strlen(chars);						/* T[0]�洢���ĳ��� */
		for(i = 1; i < T[0]; i++)
			T[i] = *(chars+i-1);
		return true;
	} 
}

/* ��ʼ�� */
bool InitBiTree(BiTree *T){
	*T = NULL;
	return true;
}

/* ���� */
void DestroyBiTree(BiTree *T){
	if(*T){
		if((*T)->lchild)							/* ������ */
			DestroyBiTree(&(*T)->lchild);
		if((*T)->rchild)							/* ���Һ��� */
			DestroyBiTree(&(*T)->rchild);
		free(*T);
		*T = 0;	
	}
} 

/* ��� */
#define ClearBiTree DestroyBiTree

/* ������������(ǰ������) */
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

/* �п� */
bool BiTreeEmpty(BiTree T){
	if(T)
		return false;
	else 
		return true;
}

/* ��� */
int BiTreeDepth(BiTree T){
	int i, j;
	
	if(!T)
		return 0;
			
	if(T->lchild)									/* ������ */
		i = BiTreeDepth(T->lchild);
	else 
		i = 0;
		
	if(T->rchild)									/* ���Һ��� */
		j = BiTreeDepth(T->rchild);
	else 
		j = 0;
	
	return i>j ? i+1 : j+1;
}

/* ���ظ� */
ElemType Root(BiTree T){
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/* ����pָ��Ľ���ֵ */
ElemType Value(BiTree p){
	return p->data;
}

/* ��p��ָ�Ľ�㸳ֵΪvalve */
void Assign(BiTree p, ElemType value){
	p->data = value;
}

/* ǰ��ݹ���� */
void PreOrderTraverse(BiTree T){
	if(T == NULL)
		return ;
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/* ����ݹ���� */
void InOrderTraverse(BiTree T){
	if(T == NULL)
		return ;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}

/* ����ݹ���� */
void PostOrderTraverse(BiTree T){
	if(T == NULL)
		return ;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}






