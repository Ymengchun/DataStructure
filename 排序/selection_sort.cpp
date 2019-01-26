#include <stdio.h>

void swap(int arr[], int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
} 

void selection_sort(int arr[], int length){
	int i, j, min;
	
	for(i = 0; i < length; i++){
		min = i;
		for(j = i + 1; j < length; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if(i != min){
			swap(arr, i, min);
		}
	}
}

int main(void){
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	selection_sort(a, 10);

	printf("简单选择排序的结果：");
	for( i=0; i < 10; i++ ){
		printf("%3d", a[i]);
	}
	printf("\n");

	return 0;
}
