#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int top1;								//栈1的栈顶指针
	int top2;								//栈2的栈顶指针
} DoubleStack;

//构造一个空栈
void InitStack(DoubleStack &s){
	s.top1 = -1;
	s.top2 = MAXSIZE;
}

//清空
void ClearStack(DoubleStack &s){
	s.top1 = -1;
	s.top2 = MAXSIZE;
}

//判空
bool StackEmpty(DoubleStack s){
	if(s.top1 == -1 && s.top2 == MAXSIZE)
		return true;
	else
		return false;
}

//求栈长
int StackLength(DoubleStack s){
	return (s.top1+1) + (MAXSIZE-s.top2); //不理解的话可以假设栈2为空
}

//入栈
bool Push(DoubleStack &s, ElemType e, int StackNumber){
	if(s.top1+1 == s.top2)				  //栈满
	 	return false;
	if(StackNumber == 1)
		s.data[++s.top1] = e;
	if(StackNumber == 2)
		s.data[--s.top2] = e;
	return true;
}

//出栈
bool Pop(DoubleStack &s, ElemType &e, int StackNumber){
	if (StackNumber == 1){
        if (s.top1 == -1)
            return false;
        e = s.data[s.top1--];
    }
    if (StackNumber == 2){
    	if (s.top2 == MAXSIZE)
            return false;
        e = s.data[s.top2++];
    }
	return true;
}

//遍历输出
void StackTraverse(DoubleStack s){
	int i = 0;
	while(i <= s.top1){             //不理解可以假设栈1只有一个元素
		printf("%d ", s.data[i]);
		i++;
	}
	i = s.top2;
	while(i <= MAXSIZE){            //不理解可以假设栈2只有一个元素
		printf("%d ", s.data[i]);
		i++;
	}
}

