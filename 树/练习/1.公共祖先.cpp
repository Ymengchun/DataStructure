/*
题目：已知一棵二叉树按顺序存储结构进行存储，求编号分别为i和j的两个结点的最近的公共祖先结点的值。
算法思想：
*/
ElemType common_ancestor(SqTree T, int i, int j){
    while(T[i] != T[j]){
        if(i > j){
            i /= 2;
        }
        else{
            j /= 2;
        }
    }
    return T[i];
}
