//��������ķǵݹ��㷨
void InOrder(BiTree T){
    InitStack(s);   //��ʼ��ջ
    BiTree p = T;   //p�Ǳ���ָ��
    while(p || !IsEmpty(s)){    //p����ջ��ʱѭ������
        if(p){                  //p����
            Push(s, p);         //��ջ
            p->lchild;          //����������
        }
        else{                   //p��
            Pop(s, p);          //��ջ
            visit(p);           //���ʸý��
            p->rchild;          //����������
        }
    }
}


