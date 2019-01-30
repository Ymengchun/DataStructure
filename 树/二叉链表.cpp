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

//��������Ľṹ����
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

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

//��ʼ��
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

//���ظ���ֵ
ElemType Root(BiTree T){
	if(BiTreeEmpty(T))
		return NULL;
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

//ǰ�����
void PreOrder(BiTree T){
	if(T == NULL)   //�����������κ�ֵ
		return ;
	else{
        visit(T);               //���ʸ����
        PreOrder(T->lchild);    //�ݹ����������
        PreOrder(T->rchild);    //�ݹ����������
	}
}

//�������
void InOrder(BiTree T){
	if(T == NULL)
		return ;
	else{
        InOrder(T->lchild);   //�ݹ����������
        visit(T);             //���ʸ����
        InOrder(T->rchild);   //�ݹ����������
	}
}

//�������
void PostOrder(BiTree T){
	if(T == NULL)
		return ;
    else{
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

//��α���
void LevelOrder(BiTree T){
    InitQueue(Q);       //��ʼ������
    BiTree p;           //����ָ��

    EnQueue(Q, p);      //����������
    while(!IsEmpty(Q)){ //���в���ѭ��
        DeQueue(Q);     //����������
        visit(p);       //���ʸ����
        if(p->lchild != NULL)
            EnQueue(Q, p->lchild);  //���������գ��������������
        if(p->rchild != NULL)
            EnQueue(Q, p->rchild);  //���������գ��������������
    }
}






