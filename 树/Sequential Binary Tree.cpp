/* 顺序二叉树 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAXSIZE 100 									/* 存储空间初始分配值 */
#define MAX_TREE_SIZE 100 								/* 最大结点数 */
typedef int ElemType;
typedef ElemType SqBiTree[MAX_TREE_SIZE];

typedef struct{
	int level, order;									/* 层数，该层序号数 */
} Position;

ElemType Nil = 0;

/* 初始化 */
bool InitBiTree(SqBiTree T){
	int i;
	for(i = 0; i < MAX_TREE_SIZE; i++)
		T[i] = Nil;
	return true;
} 

/* 建立叉树 */
bool CreateBiTree(SqBiTree T){
	int i, n;
	printf("请输入结点的总数：\n");
	scanf("%d", &n);
 	printf("请按层序输入结点的值(整型):\n");
 	
 	for(i = 0; i < n; i++){
 		printf("请输入第%d个结点的值", i+1);
 		scanf("%d", &T[i]);
 		if(i!=0 && T[i]!=Nil && T[(i+1)/2-1]==Nil){		/* 此结点不为根、不为空、无双亲 */
			printf("出现无双亲的非根节点%d\n", T[i]);
 			return false;
 		}
 		i++;
	}
	while(i < MAX_TREE_SIZE){
		T[i] = 0;
		i++;
	}
}

/* 清空二叉树 */
#define ClearBiTree InitBiTree;

/* 判空 */
bool BiTreeEmpty(SqBiTree T){
	if(T[0] == Nil)
		return true;
	else 
		return false;
}

/* 深度(高度) */
int BiTreeDepth(SqBiTree T){
	int i, j = 0;
	
	for(i = MAX_TREE_SIZE-1; i >= 0; i--)				/* 找到最后一个结点 */
		if(T[i] != Nil)
			break; 
	i++;												/* 计算该结点的序号 */
	while(i >= powl(2, j))								/* 计算2的j次幂 */
		j++;				
	return j;
}

/* 求根 */
bool root(SqBiTree T, ElemType *e){
	if(BiTreeEmpty)
		return false;
	else{
		*e = T[0]; 
		return true;
	}	
}

/* 返回处于位置e(层数，该层序号)的结点的值 */
ElemType Value(SqBiTree T, Position e){
	return T[(int)powl(2, e.level-1)+e.order-2];
}

/* 给处于位置e(层，该层序号)的结点赋值 */
bool Assign(SqBiTree T, Position e, ElemType value){
	int i = (int)powl(2, e.level-1)+e.order-2;
	
}

/* 求值为e的结点的双亲 */
int Parent(SqBiTree T, ElemType e){
	int i;
	if(T[0] == Nil)										/* 空树 */
		return Nil;
	for(i = 1; i < MAX_TREE_SIZE-1; i++){
		if(T[i] == e)									/* 找到e */ 
			return(T[(i+1)/2-1]);
		return Nil;										/* 没找到e */
	}
}

/* 返回e的左孩子 */

