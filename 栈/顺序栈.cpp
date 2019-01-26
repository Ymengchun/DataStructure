//顺序栈的结构定义
typedef struct{
	ElemType data[MAXSIZE]; 	//存放栈中元素
	int top;					//栈顶指针
}SqStack;

//构造一个空栈
void InitStack(SqStack &s){
	s.top = -1;
}

//清空
void ClearStack(SqStack &s){
	s.top = -1;
}

//判空
bool StackEmpty(SqStack s){
	if(s.top == -1)
		return true;
	else
		return false;
}

//栈长
int StackLength(SqStack s){
	return s.top+1;
}

//取栈顶元素
bool GetTop(SqStack s, ElemType &e){
	if(s.top == -1)
		return false;
	else
		e = s.data[s.top];
	return true;
}

//进栈
bool Push(SqStack &s, ElemType e){
	if (s.top == MAXSIZE-1)		//栈满报错
		return false;
	s.data[++s.top] = e;			//先移动指针，再将元素入栈
	return true;
}

//出栈
bool Pop(SqStack &s, ElemType &e){
	if (s.top == -1)				//栈空报错
		return false;
	e = s.data[s.top--];			//先将元素出栈，再修改栈顶指针
	return true;
}

//从栈底到栈顶依次显示所有元素
void StackTraverse(SqStack s){
        int i;
        for(i = 0; i <= s.top; i++)
           cout<<s.data[i];
}

