#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAXSIZE 100 
typedef char ElemType;
typedef enum {Link, Thread} PointerTag;

/* 二叉树的二叉线索存储结构定义 */
typedef struct BiThrNode{
	ElemType data;							/* 数据域 */
	struct BiThrNode *lchild, *rchild;		/* 左右孩子 */
	PointerTag LTag, RTag;					/* 左右标志 */
} BiThrNode, *BiThrTree;

ElemType Nil = '#';							/* 以#表示空字符 */

/* 按前序输入线索二叉树中结点的值,构造线索二叉树 */
bool CreatBiThrTee(BiThrTree *T){
	ElemType h;
	scanf("%c", &h);
	
	if(h == Nil)
		*T = NULL;
	else{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		if(!T)
			exit(OVERFLOW);
		(*T)->data = h;						/* 生成根结点(前序) */
		CreatBiThrTee(&(*T)->lchild);		/* 递归构造左子树 */ 
		if((*T)->lchild)					/* 有左孩子 */
			(*T)->LTag = Link;
		CreatBiThrTee(&(*T)->rchild);		/* 递归构造右子树 */
		if((*T)->rchild)					/* 有右孩子 */
			(*T)->RTag = Link;
	} 
	return true;
}

BiThrTree pre; 								/* 全局变量，始终指向刚刚访问过的结点 */

/* 中序线索化 */
void InThreading(BiThrTree p){
	if(p){
		InThreading(p->lchild);				/* 递归左子树线索化 */
		if(!p->lchild){						/* 没有左孩子 */
			p->LTag = Thread;				/* 前驱线索 */
			p->lchild = pre;				/* 左孩子指针指向前驱 */
		}	
		if(!pre->rchild){					/* 前驱没有右孩子 */
			pre->RTag = Thread;				/* 后继线索 */
			pre->rchild = p;				/* 前驱右孩子指针指向后继(当前结点p) */
		}
		pre = p;							/* 保持pre指向p的前驱 */
		
		InThreading(p->rchild);				/* 递归右子树线索化 */
	}
}

/* 中序线索化(头结点) */
void InOrderThreading(BiThrTree *head, BiThrTree T){
	*head = (BiThrTree)malloc(sizeof(BiThrNode));
	if(!*head)	
		exit(OVERFLOW);
	(*head)->LTag = Link;
	(*head)->RTag = Thread;
	(*head)->rchild = (*head);
	if(!T)									/* 如果二叉树为空 */
		(*head)->lchild = (*head);
	else{									/* 如果二叉树不为空 */
		(*head)->lchild = T;
		pre = (*head);
		InThreading(T);
		pre->rchild = (*head);				/* 此时pre指向最后一个结点 */
		pre->RTag = Thread; 
		(*head)->rchild = pre;
	}
}

/* 中序遍历二叉树的非递归算法(头结点) */
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
	p = p->rchild;							/* p指向其双亲的右孩子 */
}
