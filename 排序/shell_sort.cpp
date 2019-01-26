#include <stdio.h>

void swap(int arr[], int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void shell_sort(int arr[], int len){
	int i, j, gap;
	for (gap = len/2; gap > 0; gap /= 2){
		for (i = gap; i < len; i++){
			for (j = i - gap; j >= 0 && arr[j] > arr[j+gap]; j -= gap){
				swap(arr, j, j+gap);
			}	
		}		
	}			
}

int main(void){
	int i, arr[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	shell_sort(arr, 10);

	printf("Ï£¶ûÅÅÐòµÄ½á¹û£º");
	for( i=0; i < 10; i++ ){
		printf("%3d", arr[i]);
	}
	printf("\n");

	return 0;
}
