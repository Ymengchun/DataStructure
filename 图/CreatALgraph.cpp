#inlcude <stdio.h>
#define MAXVEX 100 

/* ������� */ 
typedef struct VertexNode{
	char data;
	EdgeNode firstedge;
} VertexNode, AdjList[MAXVEX];

/* �߱��� */
typedef struct EdgeNode{
	int adjvex;
	int weight;
	struct EdgeNode *next;
} EdgeNode;


typedef struct{
	AdjList adjList;
	int NumVertex, NumEdge;	
} ALGraph;

void CreatALGraph (ALGraph G){
	int i, j, k;
	EdgeNode *e;
	
	printf("���붥�����ͱ�����\n");
	scanf("%d,%d", &G->NumVertex, &G->NumEdge);
	
	for(i = 0; i < G->NumVertex; i++){
		printf("�������%d���������Ϣ:\n", i+1);
        scanf("%d", &G->AdjList[i].data);
        G->AdjList[i].firstedge = NULL;
	}
	
	for(k = 0; k < NumEdge; k++){
		printf("�����(vi,vj)�ϵĶ������ţ�\n");
		scanf("%d,%d", &i, &j);
		e = (EdgeNde*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->AdjList[i].firstedge;
		G->adjList[i].firstedge = e;
		
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		
		e->adjvex = 1;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge;
	}
}

int main(void)
{
	
}
