#include <stdio.h>

void swap(int arr[], int i, int j){					/* 交换两元素的值 */
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int pivot(int arr[], int low, int high){			/* 找出枢纽 */ 
	int point;
	
	point = arr[low];								/* 将首元素作为point */
	while(low < high){								
		while(low < high && arr[high] >= point){	/* 从右向左找出比point小的第一个数 */ 
			high--;
		}
		swap(arr, low, high);						/* 较小的数左移，较大的数右移 */
		
		while(low < high && arr[low] <= point){		/* 从左向右找出比point大的第一个数 */
			low++;
		}
		swap(arr, low, high);						/* 较小的数左移，较大的数右移 */
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

	printf("排序后的结果是：");
	for( i=0; i < 10; i++ ){
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
