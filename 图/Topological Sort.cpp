/* 拓扑排序 */
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
	int in;											/* 顶点入度 */
	int data;
	EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct{
	AdjList adjList;
	int NumVertex, NumEdge;
} graphAdjList, *GraphAdjList;

bool TopologicalSort(GraphAdjList GL){
	EdgeNode *e;
	int i;														/* 顶点下标 */
	int top = 0;												/* 栈顶指针 */
	int k;
	int gettop;													/* 栈顶元素 */
	int count = 0;												/* 统计输出顶点的个数 */
	int *stack;													/* 建立栈存储入度为0的顶点 */
	
	stack = (int*)malloc(GL->NumVertex * sizeof(int));
	for(i = 0; i < GL->NumVertex; i++){
		if(GL->adjList[i].in == 0)
			stack[++top] = i;
	}
	
	while(top != 0){
		gettop = stack[top--];									/* 出栈 */
		printf("%d", GL->adjList[gettop].data);					/* 打印此顶点 */
		count++;												/* 统计输出顶点数 */
		
		for(e = GL->adjList[gettop].firstedge; e; e=e->next){	/* 遍历此顶点的边集 */
			k = e->adjvex;										/* k为当前顶点的邻接点 */
			if(!(--GL->adjList[k].in))							/* 将k号顶点的入度减1，判断其是否为0 */
				stack[top++] = k;								/* 若为0则入栈，以便下一次循环输出 */ 
		}
	}
	if(count < GL->NumVertex) 									/* 如果count小于顶点数，说明存在环 */
		return false;
	else 
		return true; 
} 

