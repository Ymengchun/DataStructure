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

//二叉链表的结构定义
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

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

//初始化
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

//返回根的值
ElemType Root(BiTree T){
	if(BiTreeEmpty(T))
		return NULL;
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

//前序遍历
void PreOrder(BiTree T){
	if(T == NULL)   //空树不返回任何值
		return ;
	else{
        visit(T);               //访问根结点
        PreOrder(T->lchild);    //递归遍历左子树
        PreOrder(T->rchild);    //递归遍历右子树
	}
}

//中序遍历
void InOrder(BiTree T){
	if(T == NULL)
		return ;
	else{
        InOrder(T->lchild);   //递归遍历左子树
        visit(T);             //访问根结点
        InOrder(T->rchild);   //递归遍历右子树
	}
}

//后序遍历
void PostOrder(BiTree T){
	if(T == NULL)
		return ;
    else{
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

//层次遍历
void LevelOrder(BiTree T){
    InitQueue(Q);       //初始化队列
    BiTree p;           //遍历指针

    EnQueue(Q, p);      //将根结点入队
    while(!IsEmpty(Q)){ //队列不空循环
        DeQueue(Q);     //将根结点出队
        visit(p);       //访问根结点
        if(p->lchild != NULL)
            EnQueue(Q, p->lchild);  //左子树不空，则左子树入队列
        if(p->rchild != NULL)
            EnQueue(Q, p->rchild);  //右子树不空，则右子树入队列
    }
}






