/* n����ΧȦ��������m���У����ʣ�µ��Ǽ��� */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ����ѭ������ṹ */
typedef struct Node
{
	int data;
	struct Node *next;
} Node, *LinkList;

/* ����ѭ������ */
LinkList CreateList(int length)
{
	LinkList p, head;
	head = (LinkList)malloc(sizeof(Node));
	p = head;
	LinkList s;
	int i;

	if(length != 0)
	{
		for(i = 1; i <= length; i++)
		{
			s = (LinkList)malloc(sizeof(Node));		/* ������ռ� */
			s->data = i;    
			p->next = s;							/* ������ */
			p = s;
		}
		s->next = head->next;						/* ɾ��ͷ��� */ 
	}
	free(head);										/* �ͷ�ͷ���ռ� */

	return s->next ;								/* ���ص�һ����� */
}

int main(void)
{
	int length = 41;
	int num = 3;
	int i;
	LinkList p = CreateList(length);
	LinkList temp;

	length %= num;   

	while (p != p->next )							/* ����������ж���һ����� */ 
	{
		for (i = 1; i < length; i++){ 
			p = p->next ;
		} 
		printf("%d->", p->next->data );

		temp = p->next ;				
		p->next = temp->next ;
		free(temp);
		p = p->next ;
	}
	printf("%d\n", p->data );

	return 0;
}
