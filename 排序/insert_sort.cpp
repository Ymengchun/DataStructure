#include <stdio.h>

void swap(int arr[], int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
} 

void insert_sort(int arr[], int length){
	int i, j, temp;
	
	for (i = 1; i < length; i++){
		for (j = i-1; j >= 0 && arr[j] > arr[j+1]; j--){
			swap(arr, j, j+1);
		}
	}
}

int main(void)
{
	int i, arr[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	insert_sort(arr, 10);
	printf("直接插入排序的结果为：");
	for(i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}

	return 0;
}
