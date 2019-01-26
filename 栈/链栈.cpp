#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int ElemType;

//��ջ�Ľṹ����
typedef struct Node{
	ElemType data;
	struct Node *next;
}LinkStack;
LinkStack *top;

//����һ��ͷ���
LinkStack *CreatStack(){
    LinkStack *s;
    s = (LinkStack*)malloc(sizeof(LinkStack));
    s->next = NULL;
    return s;
}

//�п�
int IsEmpty(LinkStack *s){
    return (s->next == NULL);
}

//��ջ
void Push(LinkStack *s, ElemType e){
    LinkStack *q;
    q = (LinkStack*)malloc(sizeof(LinkStack));
    q->data = e;
    q->next = s->next;
    s->next = q;
}

//��ջ
ElemType Pop(LinkStack *s, ElemType e){

    if(IsEmpty(s)){
        printf("��ջ��");
        return NULL;
    }
    else{
        LinkStack *q;       //ָ��һ��ָ�����q
        q = s->next;        //��qָ��ջ��Ԫ��
        s->next = q->next;  //��ջ
        e = q->data;        //��ջ��Ԫ�ص�ֵ����e
        free(q);
        return e;
    }
}

