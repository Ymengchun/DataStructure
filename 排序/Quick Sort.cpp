#include <stdio.h>

void swap(int arr[], int i, int j){					/* ������Ԫ�ص�ֵ */
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int pivot(int arr[], int low, int high){			/* �ҳ���Ŧ */ 
	int point;
	
	point = arr[low];								/* ����Ԫ����Ϊpoint */
	while(low < high){								
		while(low < high && arr[high] >= point){	/* ���������ҳ���pointС�ĵ�һ���� */ 
			high--;
		}
		swap(arr, low, high);						/* ��С�������ƣ��ϴ�������� */
		
		while(low < high && arr[low] <= point){		/* ���������ҳ���point��ĵ�һ���� */
			low++;
		}
		swap(arr, low, high);						/* ��С�������ƣ��ϴ�������� */
	}
	
	return low;										
}

void Qsort(int arr[], int low, int high){
	int point;
	if(low < high){
		point = pivot(arr, low, high);
		
		Qsort(arr, low, point-1);
		Qsort(arr, point+1, high);
	}
}

void quick_sort(int arr[], int len){
	Qsort(arr, 0, len-1);
}

int main(void){
	int i, a[10] = {4, 2, 5, 0, 3, 9, 1, 7, 6, 8};

	quick_sort(a, 10);

	printf("�����Ľ���ǣ�");
	for( i=0; i < 10; i++ ){
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
