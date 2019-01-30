//Õÿ∆À≈≈–Ú
bool TopSort(Graph G){
	InitStack(s);
	for(int i=0; i<G.vexnum; i++){
        if(indegree[i] == 0){
            Push(s, i);
        }
	}
	int count = 0;
	while(!IsEmpty(s)){
        Pop(s, x);
        print[count++] = x;
        for(p=G.vertices[i].firstarc; p; p=p->nextarc){
            v = p->adjvex;
            if(!(indegree[v]))
                Push(s, v);
        }
	}
	if(count < G.vexnumber)
        return false;
    else
        return true;
}

