#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

typedef int ElemType;

typedef struct DNode{
	ElemType data;
	struct DNode *prior, *next;
} DNode, *DLinkList;

/* ��ʼ�� */
void InitList(DLinkList *L){
	*L = (DLinkList)malloc(sizeof(DNode));
	if(*L == NULL)
		return ;
	(*L)->next = *L;					/* �������nextָ���Լ� */
	(*L)->prior = *L;					/* �������priorָ���Լ� */
}

/* ��� */ 
void ClearList(DLinkList *L){
	DLinkList p = (*L)->next;
	
	while(p != *L){						/* pû����ͷ */ 
		p = p->next;
		free(p->prior);
	} 
	(*L)->next = *L;
	(*L)->prior = *L;
}

/* ���� */
void DestroyList(DLinkList *L){
	ClearList(L);
	free(*L);
	*L = NULL;
}

/* �п� */
int ListEmpty(DLinkList L){
	if(L->next == L && L->prior == L)	/* ����������Ҫ�� */
		return 0;
	else 
		return 1;
}

/* �������� */
int ListLength(DLinkList L){
	DLinkList p = L->next;
	int length = 0;
	while(p != L){
		length++;
		p = p->next;
	}
	return length;
}

/* ���i��Ԫ�ص�ֵ����e���� */
bool GetElem(DLinkList L, int i, ElemType *e){
	DLinkList p = L->next;
	int j = 1;
	
	if(i<1 || i>ListLength(L))
		return false;
	while(j<i){
		j++;
		p = p->next;
	}
	*e = p->data;	
}

/* ����ֵΪe��Ԫ�ص�λ�� */
int LocateElem(DLinkList L, ElemType e){
	DLinkList p = L->next;
	int j = 0;
	
	while(p != L){
		j++;
		if(p->data == e)
			return j;
	}
	return -1;
}

/* ��cur_e��L������Ԫ����L���ǵ�һ������pri_e��������ǰ�� */
int PriorElem(DLinkList L, ElemType cur_e, ElemType *pri_e){
	DLinkList p = L->next->next;		/* pָ��ڶ���Ԫ�� */
	
	while(p != L){
		if(p->data == cur_e){
			*pri_e = p->prior->data; 
			return 1;
		}
	} 
	return -1;
}

/* ��cur_e��L������Ԫ����L���ǵ�һ������nex_e�����ĺ�� */
bool NextElem(DLinkList L, ElemType cur_e, ElemType *nex_e){
	DLinkList p = L->next->next;
	
	while(p != L){
		if(p->prior->data == cur_e){
			*nex_e = p->data;
			return true;
		}
	}
	return false;
}

/* �ڵ�i��λ�ò���Ԫ��e */ 
bool ListInsert(DLinkList *L, int i, ElemType e){
	DLinkList p = *L;					/* pָ��ͷ��� */
	DLinkList q, s;
	int j = 0;
	
	if(i<1 || i>ListLength(*L))
		return false;
	while(j < i-1){
		j++;
		p = p->next;
	}
	q = p->next;
	
	s = (DLinkList)malloc(sizeof(DNode));
	s->data = e;
	s->next = q;
	p->next = s;
	s->prior = p;
	q->prior = s;
	
	return true;
}

/* ɾ����i����㲢��e���ظý��ֵ */
bool ListDelete(DLinkList *L, int i, ElemType *e){
	DLinkList p = (*L)->next;			/* pָ��ͷ��� */
	DLinkList q;
	int j = 0;
	
	if(i<1 || i>ListLength(*L))
		return false;
	while(j < i-1){					/* �ҵ���i-1��Ԫ�� */
		j++;
		p = p->next; 
	}
	q = p->next;
	*e = q->data;
	p->next = q->next;
	q->next->prior = p;
	free(q);
	
	return 0;
}

/* ������� */
void TravelList(DLinkList L){
	DLinkList p = L->next;
	int j = 0;
	
	while(p != L){
		j++;
		printf("��%d��Ԫ�ص�ֵΪ��%d\n", j, p->data);
		p = p->next;
	}
}

/* ������� */ 
void TravelListBack(DLinkList L){
	DLinkList p = L->prior;			/* pָ��L��β��� */
	
	while(p != L){
		printf("%d", p->data);
		p = p->prior;
	}
	printf("\n");
}








