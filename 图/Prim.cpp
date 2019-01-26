/* 最小生成树Prim算法 */
 void MiniSpanTree_Prim(MGraph G){
 	int min, i, j, k;											/* i和j为顶点下标，k为 */
 	int adjvex[MAXVEX];											/* 存储顶点下标 */
 	int lowcost[MAXVEX];										/* 存储权值 */
 	adjmax[0] = 0;												/* 假设从顶点v0开始 */
 	lowcost[0] = 0;												/* 存储权值 */
 	
 	for(i = 1; i < G->num_of_vertex; i++){						/* 循环除v0以外的全部顶点 */
 		lowcost[i] = G->arc[0][i];								/* 将这些顶点与v0之间的边的权值存入lowcost[i] */
 		adjmax[i] = 0;											/* 将这些顶点全部初始化为v0 */
	}
	
	for(i = 1; i < G->num_of_vertex; i++){						/* 循环除v0以外的所有顶点 */
 		min = INFIMITY;											/* 初始化最小权值为∞ */
 		j = 1;											
 		k = 0;	
 		
 		while(j < num_of_vertex)								/* j从1开始，循环除v0以外的全部顶点 */
 		{
 			if(lowcost[j] != 0 && lowcost[j] < min){			/* 如果当前权值不为0且权值小于min */
 				min = lowcost[j];								/* 让这个权值成为min */
 				k = j;											/* 让这个权值对应的顶点下标存入k */
			}
			
			j++;
		}
		
		printf("(%d,%d)", adjvex[k], k);						/* 打印当前权值最小的边 */
		lowcost[k] = 0;											/* 将当前顶点的权值设为0，表示此顶点已经完成任务 */
	
		for(j = 1; j < G->num_of_vertex; j++){					/* 循环除v0以外的所有顶点 */
			if(lowcost[j] != 0 && G->arc[k][j] < lowcost[j]){	/* 若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值 */
				lowcost[j] = G->arc[k][j];						/* 将较小边权值存入lowcost */
				adjvex[j] = k;									/* 将下标为k的顶点存入adjvex */
			}
			
		}
	}
}
 

