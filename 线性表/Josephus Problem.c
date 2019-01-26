/* n个人围圈报数，报m出列，最后剩下的是几号 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 定义循环链表结构 */
typedef struct Node
{
	int data;
	struct Node *next;
} Node, *LinkList;

/* 创建循环链表 */
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
			s = (LinkList)malloc(sizeof(Node));		/* 分配结点空间 */
			s->data = i;    
			p->next = s;							/* 插入结点 */
			p = s;
		}
		s->next = head->next;						/* 删除头结点 */ 
	}
	free(head);										/* 释放头结点空间 */

	return s->next ;								/* 返回第一个结点 */
}

int main(void)
{
	int length = 41;
	int num = 3;
	int i;
	LinkList p = CreateList(length);
	LinkList temp;

	length %= num;   

	while (p != p->next )							/* 如果链表中有多于一个结点 */ 
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
