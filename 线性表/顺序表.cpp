typedef int ElemType;

/* 顺序表的结构定义 */
typedef struct{
	ElemType data[MAXSIZE];
	int length;										/* 线性表当前长度 */
}SqList;

/* 初始化 */
bool InitList(SqList *L){
	L->length = 0;
	return true;
}

/* 判空 */
bool ListEmpty(SqList L){
	if(L.length == 0)
		return true;
	else 
		return false;
}

/* 清空 */
bool ClearList(SqList *L){
	L->length = 0;
	return true;
}

/* 求表长 */
int ListLength(SqList L){
	return L.length;
}

/* 求第i个元素的值 */
bool GetElem(SqList L, int i, ElemType *e){
	if(L.length == 0 || i < 1 || i > L.length)	
		return false;
	*e = L.data[i-1];								/* 用e返回该元素的值 */
	return true;
}

/* 插入 */
bool ListInsert(SqList *L, int i, ElemType e){
	int k;
	
	if(L->length >= MAXSIZE)						/* 表满 */
		return false;
		
	if(i < 1 || i > L->length+1)						
		return false;
		
	if(i <= L->length) {
		for(k = L->length-1; k >= i-1; k--)			
			L->data[k+1] = L->data[k];				/* 插入位置之后的所有元素均后移 */
	}
	
	L->data[i-1] = e;								/* 插入新元素e */
	L->length++;
	return true;
}

/* 删除 */
bool ListDelete(SqList *L, int i, ElemType *e){
	int k;
	
	if(L->length <= 0)
		return false;
		
	if(i < 1 || i > L->length)
		return false;
		
	*e = L->data[i-1];								/* 用e保存删除的元素 */
	
	if(i < L->length){								/* 如果删除不是最后位置 */
		for(k = i; k < L->length; k++)
			L->data[k-1] = L->data[k];				/* 将删除位置后继元素前移 */
			
	}
	L->length--;									/* 表长减一 */
	return true; 
}

/* 查找等于e的元素的位置 */
int LocateElem(SqList L, ElemType e){
	int i;
	for(i = 0; i < L.length; i++)
		if(L.data[i] == e)
			return i+1;
	
}

/* 顺次输出 */
bool ListTraverse(SqList L)
{
	int i;
    for(i = 0; i < L.length; i++)
            printf("%d", L.data[i]);
    printf("\n");
    return true;
}

/* 求并 */
void Union(SqList *La, SqList Lb){
	int i;
	int La_len = ListLength(*La);
	int Lb_len = ListLength(Lb);
	ElemType e;
	
	for(i = 0; i < Lb_len; i++){
		GetElem(Lb, i, &e);
		if(!LocateElem(*La, e))
			ListInsert(La, ++La_len, e);
	}
}


