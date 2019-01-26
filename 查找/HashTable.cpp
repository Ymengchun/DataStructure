#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define HASHSIZE 12
#define NULLKEY -65535

typedef struct{
	int *elem;
	int count;			
} HashTable;

int m = 0;			/* ɢ�б� */

/* ��ʼ��ɢ�б� */
void InitHashTable(HashTable *H){
	int i;
	m = HASHSIZE;
	H->count = m;
	H->elem = (int *)malloc(m * sizeof(int));
	for(i = 0; i < m; i++)
		H->elem[i] = NULLKEY;
}

/* ɢ�к��� */
int Hash(int key){
	m = HASHSIZE;
	return key % m;		/* ����ȡ�෨ */
}
			
	
/* ����ؼ��� */
int InsertHash(HashTable *H, int key){
	int addr = Hash(key);	/* ��ɢ�е�ַ */
	while(H->elem[addr] != NULLKEY)
		addr = (addr+1)%m;
	H->elem[addr] = key;
}

/* ���ҹؼ��� */
bool SearchHash(HashTable H, int key, int *addr){
	*addr = Hash(key);
	while(H.elem[*addr] != key){
		*addr = (*addr+1)%m;
		if(H.elem[*addr]==NULLKEY || *addr==Hash(key))
			return false;
	}
	return true;
} 

int main(void){
	int arr[HASHSIZE] = {12,67,56,16,25,37,22,29,15,47,48,34};
	int i, p, result;
	int key = 39;
	HashTable H;
	
	InitHashTable(&H);
	for(i = 0; i < m; i++)
		InsertHash(&H, arr[i]);
	result = SearchHash(H, key, &p);
	if(result)
		printf("���� %d �ĵ�ַΪ��%d\n",key,p);
	else
		printf("����ʧ�ܣ�%d\n", key, p);
	for(i = 0; i < m; i++){
		key = arr[i];
		SearchHash(H, key, &p);
		printf("���� %d �ĵ�ַΪ��%d\n", key, p);
	}
	return 0;
}
