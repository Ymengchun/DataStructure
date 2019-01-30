//中序遍历的非递归算法
void InOrder(BiTree T){
    InitStack(s);   //初始化栈
    BiTree p = T;   //p是遍历指针
    while(p || !IsEmpty(s)){    //p空且栈空时循环结束
        if(p){                  //p不空
            Push(s, p);         //入栈
            p->lchild;          //遍历左子树
        }
        else{                   //p空
            Pop(s, p);          //出栈
            visit(p);           //访问该结点
            p->rchild;          //遍历右子树
        }
    }
}


