/* ˳������� */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAXSIZE 100 									/* �洢�ռ��ʼ����ֵ */
#define MAX_TREE_SIZE 100 								/* ������� */
typedef int ElemType;
typedef ElemType SqBiTree[MAX_TREE_SIZE];

typedef struct{
	int level, order;									/* �������ò������ */
} Position;

ElemType Nil = 0;

/* ��ʼ�� */
bool InitBiTree(SqBiTree T){
	int i;
	for(i = 0; i < MAX_TREE_SIZE; i++)
		T[i] = Nil;
	return true;
} 

/* �������� */
bool CreateBiTree(SqBiTree T){
	int i, n;
	printf("���������������\n");
	scanf("%d", &n);
 	printf("�밴�����������ֵ(����):\n");
 	
 	for(i = 0; i < n; i++){
 		printf("�������%d������ֵ", i+1);
 		scanf("%d", &T[i]);
 		if(i!=0 && T[i]!=Nil && T[(i+1)/2-1]==Nil){		/* �˽�㲻Ϊ������Ϊ�ա���˫�� */
			printf("������˫�׵ķǸ��ڵ�%d\n", T[i]);
 			return false;
 		}
 		i++;
	}
	while(i < MAX_TREE_SIZE){
		T[i] = 0;
		i++;
	}
}

/* ��ն����� */
#define ClearBiTree InitBiTree;

/* �п� */
bool BiTreeEmpty(SqBiTree T){
	if(T[0] == Nil)
		return true;
	else 
		return false;
}

/* ���(�߶�) */
int BiTreeDepth(SqBiTree T){
	int i, j = 0;
	
	for(i = MAX_TREE_SIZE-1; i >= 0; i--)				/* �ҵ����һ����� */
		if(T[i] != Nil)
			break; 
	i++;												/* ����ý������ */
	while(i >= powl(2, j))								/* ����2��j���� */
		j++;				
	return j;
}

/* ��� */
bool root(SqBiTree T, ElemType *e){
	if(BiTreeEmpty)
		return false;
	else{
		*e = T[0]; 
		return true;
	}	
}

/* ���ش���λ��e(�������ò����)�Ľ���ֵ */
ElemType Value(SqBiTree T, Position e){
	return T[(int)powl(2, e.level-1)+e.order-2];
}

/* ������λ��e(�㣬�ò����)�Ľ�㸳ֵ */
bool Assign(SqBiTree T, Position e, ElemType value){
	int i = (int)powl(2, e.level-1)+e.order-2;
	
}

/* ��ֵΪe�Ľ���˫�� */
int Parent(SqBiTree T, ElemType e){
	int i;
	if(T[0] == Nil)										/* ���� */
		return Nil;
	for(i = 1; i < MAX_TREE_SIZE-1; i++){
		if(T[i] == e)									/* �ҵ�e */ 
			return(T[(i+1)/2-1]);
		return Nil;										/* û�ҵ�e */
	}
}

/* ����e������ */

