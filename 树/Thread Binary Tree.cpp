#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAXSIZE 100 
typedef char ElemType;
typedef enum {Link, Thread} PointerTag;

/* �������Ķ��������洢�ṹ���� */
typedef struct BiThrNode{
	ElemType data;							/* ������ */
	struct BiThrNode *lchild, *rchild;		/* ���Һ��� */
	PointerTag LTag, RTag;					/* ���ұ�־ */
} BiThrNode, *BiThrTree;

ElemType Nil = '#';							/* ��#��ʾ���ַ� */

/* ��ǰ�����������������н���ֵ,�������������� */
bool CreatBiThrTee(BiThrTree *T){
	ElemType h;
	scanf("%c", &h);
	
	if(h == Nil)
		*T = NULL;
	else{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		if(!T)
			exit(OVERFLOW);
		(*T)->data = h;						/* ���ɸ����(ǰ��) */
		CreatBiThrTee(&(*T)->lchild);		/* �ݹ鹹�������� */ 
		if((*T)->lchild)					/* ������ */
			(*T)->LTag = Link;
		CreatBiThrTee(&(*T)->rchild);		/* �ݹ鹹�������� */
		if((*T)->rchild)					/* ���Һ��� */
			(*T)->RTag = Link;
	} 
	return true;
}

BiThrTree pre; 								/* ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ�� */

/* ���������� */
void InThreading(BiThrTree p){
	if(p){
		InThreading(p->lchild);				/* �ݹ������������� */
		if(!p->lchild){						/* û������ */
			p->LTag = Thread;				/* ǰ������ */
			p->lchild = pre;				/* ����ָ��ָ��ǰ�� */
		}	
		if(!pre->rchild){					/* ǰ��û���Һ��� */
			pre->RTag = Thread;				/* ������� */
			pre->rchild = p;				/* ǰ���Һ���ָ��ָ����(��ǰ���p) */
		}
		pre = p;							/* ����preָ��p��ǰ�� */
		
		InThreading(p->rchild);				/* �ݹ������������� */
	}
}

/* ����������(ͷ���) */
void InOrderThreading(BiThrTree *head, BiThrTree T){
	*head = (BiThrTree)malloc(sizeof(BiThrNode));
	if(!*head)	
		exit(OVERFLOW);
	(*head)->LTag = Link;
	(*head)->RTag = Thread;
	(*head)->rchild = (*head);
	if(!T)									/* ���������Ϊ�� */
		(*head)->lchild = (*head);
	else{									/* �����������Ϊ�� */
		(*head)->lchild = T;
		pre = (*head);
		InThreading(T);
		pre->rchild = (*head);				/* ��ʱpreָ�����һ����� */
		pre->RTag = Thread; 
		(*head)->rchild = pre;
	}
}

/* ��������������ķǵݹ��㷨(ͷ���) */
void InOrderTraverse_Thr(BiThrTree head){
	BiThrTree p;
	p = head->lchild;
	while(p != head){
		while(p->LTag == Link)
			p = p->lchild;
		printf("%c", p->data);
	}
	while(p->RTag==Thread && p->rchild !=head){
		p = p->rchild;
		printf("%c", p->data);
	}	
	p = p->rchild;							/* pָ����˫�׵��Һ��� */
}
