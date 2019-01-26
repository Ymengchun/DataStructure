typedef Boolean;
Boolean visted[MAX];

/* 邻接矩阵的深度优先遍历算法 */
void DFS(MGraph G, int i){
	int j;
	
	visited[i] = TRUE;
	printf("%c", G.vex[i]);
	for(j = 0; j < G.NumVertex; j++){
		if(G.arc[i][j] == 1 && !visited[j]){
			DFS(G, j);
		}		
	}
}

/* 邻接矩阵的深度优先遍历操作 */
void DFSTraverse(MGraph G){
	int i;
	for(i = 0; i < G.NumVertex; i++){
		visited[i] = FALSE;
	}
	
	for(i = 0; i < G.NumVertex; i++){
		if(!visted[i]){
			DFS(G, i);
		}
	}
}

