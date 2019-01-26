#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define HASHSIZE 12
#define NULLKEY -65535

typedef struct{
	int *elem;
	int count;			
} HashTable;

int m = 0;			/* 散列表长 */

/* 初始化散列表 */
void InitHashTable(HashTable *H){
	int i;
	m = HASHSIZE;
	H->count = m;
	H->elem = (int *)malloc(m * sizeof(int));
	for(i = 0; i < m; i++)
		H->elem[i] = NULLKEY;
}

/* 散列函数 */
int Hash(int key){
	m = HASHSIZE;
	return key % m;		/* 除留取余法 */
}
			
	
/* 插入关键字 */
int InsertHash(HashTable *H, int key){
	int addr = Hash(key);	/* 求散列地址 */
	while(H->elem[addr] != NULLKEY)
		addr = (addr+1)%m;
	H->elem[addr] = key;
}

/* 查找关键字 */
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
		printf("查找 %d 的地址为：%d\n",key,p);
	else
		printf("查找失败：%d\n", key, p);
	for(i = 0; i < m; i++){
		key = arr[i];
		SearchHash(H, key, &p);
		printf("查找 %d 的地址为：%d\n", key, p);
	}
	return 0;
}
