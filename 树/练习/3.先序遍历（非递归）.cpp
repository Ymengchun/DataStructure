//��������ķǵݹ��㷨
void PreOrder(BiTree T){
    InitStack(s);
    BiTree p;

    while(p || !IsEmpty(s)){
        if(p){
            visit(p);
            Push(s, p);
            p = p->lchild;
        }
        else{
            Pop(s, p);
            p = p->rchild;
        }
    }
}
