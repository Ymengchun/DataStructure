typedef Boolean;
Boolean visted[MAX];

/* �ڽӾ����������ȱ����㷨 */
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

/* �ڽӾ����������ȱ������� */
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

