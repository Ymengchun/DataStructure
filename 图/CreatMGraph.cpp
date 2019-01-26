#include <stdio.h>
#define MAXVEX 100
#define INFINITY 65535										/* ��65535��ʾ����� */

typedef struct {
	char vex[MAXVEX];										/* һά����洢���� */ 
	int arc[MAXVEX][MAXVEX];								/* ��ά����洢�� */
	int NumVertex, NumEdge;									/* �������ͱ��� */
}MGraph;

/* �����ڽӾ��� */ 
void CreatMGraph(MGraph *G){
	int i, j, k, w;
	
	printf("���붥�����ͱ�����\n");
	scanf("%d,%d", &G->NumVertex, &G->NumEdge);				/* ���붥�����ͱ��� */
	
	for(i = 0; i < G->NumVertex; i++){						/* ������������ */
		printf("�������%d���������Ϣ:\n", i+1);
        scanf("%d", &G->vex[i]);
	}
	
	for(i = 0; i < G->NumVertex; i++)						/* ��ʼ�������� */
		for(j = 0; j < G->NumVertex; j++){
			if(i == j){
				G->arc[i][j] = 0;
			}
			else{
				G->arc[i][j] = INFINITY;
			}
		}
															
	for(k = 0; k < G->NumEdge; k++) 						/* ���������� */
	{
		printf("�����(vi,vj)�ϵ��±�i���±�j��Ȩw(��(0,0)��ʼ)��\n");
		scanf("%d,%d,%d", &i, &j, &w); 						/* ����(vi,vj)�ϵ�Ȩ */
		G->arc[i][j] = w; 
		G->arc[j][i]= G->arc[i][j]; 						/* ����ͼ�Գ� */
	}
}
	
/* ��ӡ�ڽӾ��� */
void PrintMGraph(MGraph *G) 								
{ 
    int i, j;
    
    printf("����������Ϣ:\n");
    for(i = 0; i < G->NumVertex; i++)
        printf("%8d", G->vex[i]);

    printf("\n����ڽӾ���:\n");
    printf("\t");
    
    for(i = 0; i < G->NumVertex; i++){
        printf("%8d", G->vex[i]);
	}
	printf("\n"); 

    for(i = 0; i < G->NumVertex; i++){ 
        printf("\n%8d", i+1);
        
        for(j = 0; j < G->NumVertex; j++){ 
        	if(G->arc[i][j] == 65535){
            	printf("%8s", "��");
            }
        	else{
            	printf("%8d", G->arc[i][j]);
        	}
        }
        printf("\n");   
    }
}
int main(void){
	MGraph G;
	CreatMGraph(&G); 
	PrintMGraph(&G);
	
	return 0;
}
