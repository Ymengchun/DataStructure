#include <stdio.h>
#define MAXVEX 100
#define INFINITY 65535										/* 用65535表示无穷大 */

typedef struct {
	char vex[MAXVEX];										/* 一维数组存储顶点 */ 
	int arc[MAXVEX][MAXVEX];								/* 二维数组存储边 */
	int NumVertex, NumEdge;									/* 顶点数和边数 */
}MGraph;

/* 创建邻接矩阵 */ 
void CreatMGraph(MGraph *G){
	int i, j, k, w;
	
	printf("输入顶点数和边数：\n");
	scanf("%d,%d", &G->NumVertex, &G->NumEdge);				/* 输入顶点数和边数 */
	
	for(i = 0; i < G->NumVertex; i++){						/* 建立顶点数组 */
		printf("请输入第%d个顶点的信息:\n", i+1);
        scanf("%d", &G->vex[i]);
	}
	
	for(i = 0; i < G->NumVertex; i++)						/* 初始化边数组 */
		for(j = 0; j < G->NumVertex; j++){
			if(i == j){
				G->arc[i][j] = 0;
			}
			else{
				G->arc[i][j] = INFINITY;
			}
		}
															
	for(k = 0; k < G->NumEdge; k++) 						/* 建立边数组 */
	{
		printf("输入边(vi,vj)上的下标i，下标j，权w(从(0,0)开始)：\n");
		scanf("%d,%d,%d", &i, &j, &w); 						/* 输入(vi,vj)上的权 */
		G->arc[i][j] = w; 
		G->arc[j][i]= G->arc[i][j]; 						/* 无向图对称 */
	}
}
	
/* 打印邻接矩阵 */
void PrintMGraph(MGraph *G) 								
{ 
    int i, j;
    
    printf("输出顶点的信息:\n");
    for(i = 0; i < G->NumVertex; i++)
        printf("%8d", G->vex[i]);

    printf("\n输出邻接矩阵:\n");
    printf("\t");
    
    for(i = 0; i < G->NumVertex; i++){
        printf("%8d", G->vex[i]);
	}
	printf("\n"); 

    for(i = 0; i < G->NumVertex; i++){ 
        printf("\n%8d", i+1);
        
        for(j = 0; j < G->NumVertex; j++){ 
        	if(G->arc[i][j] == 65535){
            	printf("%8s", "∞");
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
