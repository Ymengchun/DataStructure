/* �߼����� */
typedef struct{
	int begin;
	int end;
	int weight;
} Edge;

/* Kruskal�㷨������С������ */
void MiniSpanTree_Kruskal(MGraph G){
	int i, n, m;
	Edge edge[MAXVEX];
	int parent[MAXVEX];
	
	for(i = 0; i < G->num_of_vertex; i++){
		parent[i] = 0;
	}
	
	for(i = 0; i < G->num_of_edge; i++){
		
	}
	
	
	
}

int Find(int *parent, int i){
	while(parent(i) > 0){
		i = parent[i];
	}
	
	return i;
} 
