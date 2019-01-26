#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef int ElemType;

typedef struct Node{
	int data;
	struct Node *next;
} Node, *LinkList;

/* ��ʼ�� */ 
bool InitList(LinkList *L){
	*L = (LinkList)malloc(sizeof(Node));			/* ����ͷ��� */ 
	if(*L == NULL)									/* ����ʧ�� */ 
		return false;
	(*L)->next = *L;								/* ָ����ָ���� */
}

/* ��� */
void ClearList(LinkList *L){
	LinkList p, q;
	*L = (*L)->next;
	p = (*L)->next;
	
	while(p != *L){									/* pδ����ͷ */ 
		q = p->next;
		free(q);
		p = q;
	}
	(*L)->next = *L;								/* ָ����ָ���� */
}

void DestroyList(LinkList *L)
{
     ClearList(L);
     free(*L); 										/* �ͷ�ͷ��� */ 
    *L = NULL;
}

/* �п� */
int ListEmpty(LinkList L){
	if(L->next ==L)
		return 0;
	else 
		return 1;
}

/* �󳤶� */
int ListLength(LinkList L){
	LinkList p = L->next;
	int j = 0;
	
	while(p != L){
		j++;
		p = p->next;
	}
	return j;
}

bool GetElem(LinkList L, int i, ElemType *e){
	LinkList p = L->next;
	int j = 0;
	
	if(i<1 || i>ListLength(L))
		return false;
	while(j < i){
		j++;
		p = p->next;
	}
	*e = p->data;
}

int LocateElem(LinkList L, ElemType e){
	LinkList p = L->next;
	int j = 0;
	
	while(p != L){
		j++;
		if(p->data == e)
			return j;
		p = p->next;
	}
}

void PriorElem(LinkList L, ElemType cur_e, ElemType *pri_e){
	LinkList p = L->next;
	LinkList q;
	
	while(p != L){
		q = p->next;
		if(q != L && q->data == cur_e)
			*pri_e = p->data;
	}
	p = q;
}

void NextElem(LinkList L, ElemType cur_e, ElemType *nex_e){
	LinkList p = L->next;
	LinkList q;
	while(p != L){
		q = p->next;
		if(q != L && p->data == cur_e){
			*nex_e = q->data;
		}
	}
	p = q;
}

bool ListInsert(LinkList *L, int i, ElemType e){
	LinkList p = (*L)->next;
	LinkList q, s;
	int j = 0;
	
	if(i<1 || i>ListLength(*L)+1)
		return false;
	while(j < i-1){
		j++;
		p = p->next;
	}
	q = p->next;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = q;
	p->next = s;
	if(p == *L)
		*L = s;
}

/* ɾ����i��Ԫ�ز���e���� */
bool ListDelete(LinkList *L, int i, ElemType *e){
	LinkList p = (*L)->next;
	LinkList q;
	int j = 0;
	if(i<1 && i>ListLength(*L))
		return false;
	while(j<i-1){
		j++;
		p = p->next;
	}
	q = p->next;
	*e = q->data;
	p->next = q->next;
	if(q == *L)
		*L = p;
	free(q);
}

/* ��������ӡL */
void TravelList(LinkList L){
	LinkList p = L->next;								/* pָ���һ����� */
	int j = 0;
	while(p != L){
		j++;
		printf("��%d��Ԫ��Ϊ��%d", j, p->data);
		p = p->next;
	} 
} 
