#include <stdio.h>
#define MAXSIZE 100

void Fibonacci(int f[]){							/* 递归定义斐波那契数列 */ 
	int i;

	f[0] = 1;
	f[1] = 1;
	
	for(i=2; i < MAXSIZE; i++)
		f[i] = f[i-2] + f[i-1];

}

int Fibonacci_Search(int a[], int n, int key)
{
	int low = 0;									/* 头指针 */ 
	int high = n - 1;								/* 尾指针 */ 
	int mid = 0;									/* 分界指针 */ 
	int k = 0;										/* 初始化数组下标 */ 
	int F[MAXSIZE];
	int i; 
	
	Fibonacci(F);
	 
	while (n > F[k] - 1)	//找到k使F[k-1]<n<F[k] 
		k++;
		
	for (i = n; i < F[k] - 1; i++)	//用最大值填充数组，-1是计算下标 
		a[i] = a[high];
		
	while (low <= high)
	{
		mid = low + F[k-1] - 1;		//计算分界点下标 
		
		if (key < a[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		
		else if (key > a[mid])
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= n)
				return mid;		//若相等则说明mid即为查找到的位置 
			else
				return high;	//若mid>n说明是补全值 
		}
	}
	return -1;	
}
	
int main(void){
	
	int a[MAXSIZE] = {1, 5, 15, 22, 25, 31, 39, 42, 47, 49, 59, 68, 88};
	int key;
	int result;

	printf("您想查找的关键字是：");
	scanf("%d", &key);
	
	result = Fibonacci_Search(a, 13, key);
	
	if( result != -1)
		printf("\n您所查找的关键字的数组下标是%d\n\n", result);
	else
	{
		printf("\n没有您想查找的关键字%d\n\n", key);
	}
		
	return 0;
}
