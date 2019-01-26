/* ��С������Prim�㷨 */
 void MiniSpanTree_Prim(MGraph G){
 	int min, i, j, k;											/* i��jΪ�����±꣬kΪ */
 	int adjvex[MAXVEX];											/* �洢�����±� */
 	int lowcost[MAXVEX];										/* �洢Ȩֵ */
 	adjmax[0] = 0;												/* ����Ӷ���v0��ʼ */
 	lowcost[0] = 0;												/* �洢Ȩֵ */
 	
 	for(i = 1; i < G->num_of_vertex; i++){						/* ѭ����v0�����ȫ������ */
 		lowcost[i] = G->arc[0][i];								/* ����Щ������v0֮��ıߵ�Ȩֵ����lowcost[i] */
 		adjmax[i] = 0;											/* ����Щ����ȫ����ʼ��Ϊv0 */
	}
	
	for(i = 1; i < G->num_of_vertex; i++){						/* ѭ����v0��������ж��� */
 		min = INFIMITY;											/* ��ʼ����СȨֵΪ�� */
 		j = 1;											
 		k = 0;	
 		
 		while(j < num_of_vertex)								/* j��1��ʼ��ѭ����v0�����ȫ������ */
 		{
 			if(lowcost[j] != 0 && lowcost[j] < min){			/* �����ǰȨֵ��Ϊ0��ȨֵС��min */
 				min = lowcost[j];								/* �����Ȩֵ��Ϊmin */
 				k = j;											/* �����Ȩֵ��Ӧ�Ķ����±����k */
			}
			
			j++;
		}
		
		printf("(%d,%d)", adjvex[k], k);						/* ��ӡ��ǰȨֵ��С�ı� */
		lowcost[k] = 0;											/* ����ǰ�����Ȩֵ��Ϊ0����ʾ�˶����Ѿ�������� */
	
		for(j = 1; j < G->num_of_vertex; j++){					/* ѭ����v0��������ж��� */
			if(lowcost[j] != 0 && G->arc[k][j] < lowcost[j]){	/* ���±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ */
				lowcost[j] = G->arc[k][j];						/* ����С��Ȩֵ����lowcost */
				adjvex[j] = k;									/* ���±�Ϊk�Ķ������adjvex */
			}
			
		}
	}
}
 

