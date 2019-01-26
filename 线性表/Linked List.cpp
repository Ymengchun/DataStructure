#include<iostream>
using namespace std;
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//头插法建立单链表
LinkList CreatList1(LinkList &L){
    LinkList s;
    int x;
    L = new LNode;
    L->next = NULL;
    cin>>x;
    while(x != 9999){
        s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin>>x;
    }
    return L;
}

int main(){
	LinkList L = new LNode(10);
	for(int i=0; i<9; i++){
        CreatList1(L, i);
	}

	return 0;
}
