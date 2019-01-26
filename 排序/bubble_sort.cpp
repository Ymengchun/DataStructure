#include <stdio.h>

void swap(int arr[], int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

/*从i=0开始，遍历整个数组 ；
  对于每一个i，从j=i+1开始，遍历整个数组；
  如果arr[i]>arr[j]，交换两个元素； 
*/
void bubble_sort0(int arr[], int length){	/* 可能把较小的key交换到较后的位置 */ 
	int i, j;
	for(i = 0; i < length; i++){
		for(j = i+1; j < length; j++){
			if(arr[i] > arr[j]){
				swap(arr, i, j);
			}
		}
	}
}

void bubble_sort1(int arr[], int length){	/* 冒泡排序 */
	int i, j;
	for(i = 0; i < length; i++){
		for(j = length-1; j >= i; j--){
			if(arr[j] > arr[j+1]){
				swap(arr, j, j+1);
			}
		}
	}
}

void bubble_sort2(int arr[], int length){	/* 对于已经有序的key不进行比较 */
	int i, j;
	int flag = 1;
	
	for(i = 0; i < length && flag; i++){
		flag = 0;
		for(j = length-1; j >= i; j--){
			if(arr[j] > arr[j+1]){
				swap(arr, j, j+1);
				flag = 1;
			}
		}
	}	
}

int main(void){
	int i, arr[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	bubble_sort0(arr, 10);
	printf("bubble_sort0的结果：");
	for(i = 0; i < 10; i++ ){
		printf("%3d", arr[i]);
	}
	printf("\n");
	
	bubble_sort1(arr, 10);
	printf("bubble_sort1的结果：");
	for(i=0; i < 10; i++ ){
		printf("%3d", arr[i]);
	}
	printf("\n");
	
	bubble_sort2(arr, 10);
	printf("bubble_sort2的结果：");
	for(i=0; i < 10; i++ ){
		printf("%3d", arr[i]);
	}
	printf("\n");

	return 0;
}
