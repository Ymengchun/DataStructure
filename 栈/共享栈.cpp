#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int top1;								//ջ1��ջ��ָ��
	int top2;								//ջ2��ջ��ָ��
} DoubleStack;

//����һ����ջ
void InitStack(DoubleStack &s){
	s.top1 = -1;
	s.top2 = MAXSIZE;
}

//���
void ClearStack(DoubleStack &s){
	s.top1 = -1;
	s.top2 = MAXSIZE;
}

//�п�
bool StackEmpty(DoubleStack s){
	if(s.top1 == -1 && s.top2 == MAXSIZE)
		return true;
	else
		return false;
}

//��ջ��
int StackLength(DoubleStack s){
	return (s.top1+1) + (MAXSIZE-s.top2); //�����Ļ����Լ���ջ2Ϊ��
}

//��ջ
bool Push(DoubleStack &s, ElemType e, int StackNumber){
	if(s.top1+1 == s.top2)				  //ջ��
	 	return false;
	if(StackNumber == 1)
		s.data[++s.top1] = e;
	if(StackNumber == 2)
		s.data[--s.top2] = e;
	return true;
}

//��ջ
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

//�������
void StackTraverse(DoubleStack s){
	int i = 0;
	while(i <= s.top1){             //�������Լ���ջ1ֻ��һ��Ԫ��
		printf("%d ", s.data[i]);
		i++;
	}
	i = s.top2;
	while(i <= MAXSIZE){            //�������Լ���ջ2ֻ��һ��Ԫ��
		printf("%d ", s.data[i]);
		i++;
	}
}

