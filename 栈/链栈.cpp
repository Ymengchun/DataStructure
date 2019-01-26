#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int ElemType;

//链栈的结构定义
typedef struct Node{
	ElemType data;
	struct Node *next;
}LinkStack;
LinkStack *top;

//生成一个头结点
LinkStack *CreatStack(){
    LinkStack *s;
    s = (LinkStack*)malloc(sizeof(LinkStack));
    s->next = NULL;
    return s;
}

//判空
int IsEmpty(LinkStack *s){
    return (s->next == NULL);
}

//入栈
void Push(LinkStack *s, ElemType e){
    LinkStack *q;
    q = (LinkStack*)malloc(sizeof(LinkStack));
    q->data = e;
    q->next = s->next;
    s->next = q;
}

//出栈
ElemType Pop(LinkStack *s, ElemType e){

    if(IsEmpty(s)){
        printf("堆栈空");
        return NULL;
    }
    else{
        LinkStack *q;       //指定一个指针变量q
        q = s->next;        //让q指向栈顶元素
        s->next = q->next;  //出栈
        e = q->data;        //将栈顶元素的值赋给e
        free(q);
        return e;
    }
}

