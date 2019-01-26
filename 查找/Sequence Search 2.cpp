#include <stdio.h>

int sequencial_search(int a[], int n, int key)
{
	int i;
	
	for (i = 0; i < n; i++)
		if(a[i] == key)
			return i;
}

int main(void)
{
	int result; 
	int a[] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
	
	result = sequencial_search(a, 11, 62);
	printf("顺序查找的结果：%d", result);
	
	return 0;
}
