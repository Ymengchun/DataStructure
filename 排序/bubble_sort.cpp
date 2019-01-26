#include <stdio.h>

void swap(int arr[], int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

/*��i=0��ʼ�������������� ��
  ����ÿһ��i����j=i+1��ʼ�������������飻
  ���arr[i]>arr[j]����������Ԫ�أ� 
*/
void bubble_sort0(int arr[], int length){	/* ���ܰѽ�С��key�������Ϻ��λ�� */ 
	int i, j;
	for(i = 0; i < length; i++){
		for(j = i+1; j < length; j++){
			if(arr[i] > arr[j]){
				swap(arr, i, j);
			}
		}
	}
}

void bubble_sort1(int arr[], int length){	/* ð������ */
	int i, j;
	for(i = 0; i < length; i++){
		for(j = length-1; j >= i; j--){
			if(arr[j] > arr[j+1]){
				swap(arr, j, j+1);
			}
		}
	}
}

void bubble_sort2(int arr[], int length){	/* �����Ѿ������key�����бȽ� */
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
	printf("bubble_sort0�Ľ����");
	for(i = 0; i < 10; i++ ){
		printf("%3d", arr[i]);
	}
	printf("\n");
	
	bubble_sort1(arr, 10);
	printf("bubble_sort1�Ľ����");
	for(i=0; i < 10; i++ ){
		printf("%3d", arr[i]);
	}
	printf("\n");
	
	bubble_sort2(arr, 10);
	printf("bubble_sort2�Ľ����");
	for(i=0; i < 10; i++ ){
		printf("%3d", arr[i]);
	}
	printf("\n");

	return 0;
}
