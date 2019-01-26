#include <stdio.h>
#define MAXSIZE 100

void Fibonacci(int f[]){							/* �ݹ鶨��쳲��������� */ 
	int i;

	f[0] = 1;
	f[1] = 1;
	
	for(i=2; i < MAXSIZE; i++)
		f[i] = f[i-2] + f[i-1];

}

int Fibonacci_Search(int a[], int n, int key)
{
	int low = 0;									/* ͷָ�� */ 
	int high = n - 1;								/* βָ�� */ 
	int mid = 0;									/* �ֽ�ָ�� */ 
	int k = 0;										/* ��ʼ�������±� */ 
	int F[MAXSIZE];
	int i; 
	
	Fibonacci(F);
	 
	while (n > F[k] - 1)	//�ҵ�kʹF[k-1]<n<F[k] 
		k++;
		
	for (i = n; i < F[k] - 1; i++)	//�����ֵ������飬-1�Ǽ����±� 
		a[i] = a[high];
		
	while (low <= high)
	{
		mid = low + F[k-1] - 1;		//����ֽ���±� 
		
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
				return mid;		//�������˵��mid��Ϊ���ҵ���λ�� 
			else
				return high;	//��mid>n˵���ǲ�ȫֵ 
		}
	}
	return -1;	
}
	
int main(void){
	
	int a[MAXSIZE] = {1, 5, 15, 22, 25, 31, 39, 42, 47, 49, 59, 68, 88};
	int key;
	int result;

	printf("������ҵĹؼ����ǣ�");
	scanf("%d", &key);
	
	result = Fibonacci_Search(a, 13, key);
	
	if( result != -1)
		printf("\n�������ҵĹؼ��ֵ������±���%d\n\n", result);
	else
	{
		printf("\nû��������ҵĹؼ���%d\n\n", key);
	}
		
	return 0;
}
