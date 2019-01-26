/* �������� */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#define MAXVEX 100

typedef struct EdgeNode{
	int adjvex;
	int weight;
	struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode{
	int in;											/* ������� */
	int data;
	EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct{
	AdjList adjList;
	int NumVertex, NumEdge;
} graphAdjList, *GraphAdjList;

bool TopologicalSort(GraphAdjList GL){
	EdgeNode *e;
	int i;														/* �����±� */
	int top = 0;												/* ջ��ָ�� */
	int k;
	int gettop;													/* ջ��Ԫ�� */
	int count = 0;												/* ͳ���������ĸ��� */
	int *stack;													/* ����ջ�洢���Ϊ0�Ķ��� */
	
	stack = (int*)malloc(GL->NumVertex * sizeof(int));
	for(i = 0; i < GL->NumVertex; i++){
		if(GL->adjList[i].in == 0)
			stack[++top] = i;
	}
	
	while(top != 0){
		gettop = stack[top--];									/* ��ջ */
		printf("%d", GL->adjList[gettop].data);					/* ��ӡ�˶��� */
		count++;												/* ͳ����������� */
		
		for(e = GL->adjList[gettop].firstedge; e; e=e->next){	/* �����˶���ı߼� */
			k = e->adjvex;										/* kΪ��ǰ������ڽӵ� */
			if(!(--GL->adjList[k].in))							/* ��k�Ŷ������ȼ�1���ж����Ƿ�Ϊ0 */
				stack[top++] = k;								/* ��Ϊ0����ջ���Ա���һ��ѭ����� */ 
		}
	}
	if(count < GL->NumVertex) 									/* ���countС�ڶ�������˵�����ڻ� */
		return false;
	else 
		return true; 
} 

