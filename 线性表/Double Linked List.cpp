#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

typedef int ElemType;

typedef struct DNode{
	ElemType data;
	struct DNode *prior, *next;
} DNode, *DLinkList;

/* 初始化 */
void InitList(DLinkList *L){
	*L = (DLinkList)malloc(sizeof(DNode));
	if(*L == NULL)
		return ;
	(*L)->next = *L;					/* 空链表的next指向自己 */
	(*L)->prior = *L;					/* 空链表的prior指向自己 */
}

/* 清空 */ 
void ClearList(DLinkList *L){
	DLinkList p = (*L)->next;
	
	while(p != *L){						/* p没到表头 */ 
		p = p->next;
		free(p->prior);
	} 
	(*L)->next = *L;
	(*L)->prior = *L;
}

/* 销毁 */
void DestroyList(DLinkList *L){
	ClearList(L);
	free(*L);
	*L = NULL;
}

/* 判空 */
int ListEmpty(DLinkList L){
	if(L->next == L && L->prior == L)	/* 两个条件都要有 */
		return 0;
	else 
		return 1;
}

/* 求链表长度 */
int ListLength(DLinkList L){
	DLinkList p = L->next;
	int length = 0;
	while(p != L){
		length++;
		p = p->next;
	}
	return length;
}

/* 求第i个元素的值并用e返回 */
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

/* 查找值为e的元素的位置 */
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

/* 若cur_e是L的数据元素且L不是第一个，用pri_e返回它的前驱 */
int PriorElem(DLinkList L, ElemType cur_e, ElemType *pri_e){
	DLinkList p = L->next->next;		/* p指向第二个元素 */
	
	while(p != L){
		if(p->data == cur_e){
			*pri_e = p->prior->data; 
			return 1;
		}
	} 
	return -1;
}

/* 若cur_e是L的数据元素且L不是第一个，用nex_e回它的后继 */
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

/* 在第i个位置插入元素e */ 
bool ListInsert(DLinkList *L, int i, ElemType e){
	DLinkList p = *L;					/* p指向头结点 */
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

/* 删除第i个结点并用e返回该结点值 */
bool ListDelete(DLinkList *L, int i, ElemType *e){
	DLinkList p = (*L)->next;			/* p指向头结点 */
	DLinkList q;
	int j = 0;
	
	if(i<1 || i>ListLength(*L))
		return false;
	while(j < i-1){					/* 找到第i-1个元素 */
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

/* 正序输出 */
void TravelList(DLinkList L){
	DLinkList p = L->next;
	int j = 0;
	
	while(p != L){
		j++;
		printf("第%d个元素的值为：%d\n", j, p->data);
		p = p->next;
	}
}

/* 倒序输出 */ 
void TravelListBack(DLinkList L){
	DLinkList p = L->prior;			/* p指向L的尾结点 */
	
	while(p != L){
		printf("%d", p->data);
		p = p->prior;
	}
	printf("\n");
}








