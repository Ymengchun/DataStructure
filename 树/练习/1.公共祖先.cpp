/*
��Ŀ����֪һ�ö�������˳��洢�ṹ���д洢�����ŷֱ�Ϊi��j��������������Ĺ������Ƚ���ֵ��
�㷨˼�룺
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
