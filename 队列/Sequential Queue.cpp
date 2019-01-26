#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int front;
	int rear;
} SqQueue;

/* 初始化队列 */
void InitQueue(SqQueue *Q){
	Q->front = 0;
	Q->rear = 0;
}

/* 清空队列 */
void ClearQueue(SqQueue *Q){
	Q->front = 0;
	Q->rear = 0;
}

/* 判空 */
bool QueueEmpty(SqQueue Q){
	if(Q.front == Q.rear)					/* 队列空的标志 */
		return true;
	else 
		return false;
}

/* 队列长度 */
int QueueLength(SqQueue Q){
	return 	(Q.front-Q.rear+MAXSIZE)%MAXSIZE;
}

/* 求队头元素 */
bool GetHead(SqQueue Q, ElemType *e){
	if(Q.front == Q.rear)
		return false;
	*e = Q.data[Q.front];
}

/* 入队 */
bool EnQueue(SqQueue *Q, ElemType e){
	if((Q->rear+1)%MAXSIZE==Q->front) 
		return false;					/* 栈满 */
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	return true;
}

/* 出队 */
bool DeQueue(SqQueue *Q, ElemType *e){
	if(Q->rear == Q->front)					/* 栈空 */
		return false;
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return true;
}

/* 遍历输出 */
void QueueTraverse(SqQueue Q){
	int i = Q.front;
	while((i+Q.front) != Q.rear){
		printf("%d", Q.data[i]);
		i = (i+1)%MAXSIZE;
	}
	printf("\n");
}


