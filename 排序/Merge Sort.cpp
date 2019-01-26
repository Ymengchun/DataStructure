#include <stdio.h>
#define MAXSIZE 10

void merge(int *list1, int list1_size, int *list2, int list2_size){
	int temp[MAXSIZE];
	int i, j, k, m;	//i,j,k分别是list1,list2,temp的指针 
	i = j = k = 0;
	
	while (i < list1_size && j < list2_size){
		if(list1[i] < list2[j])
			temp[k++] = list1[i++];
		else
			temp[k++] = list2[j++];
	}
	
	while (i < list1_size)
		temp[k++] = list1[i++];
		
	while (j < list2_size)
		temp[k++] = list2[j++];
	
	for(m = 0; m < (list1_size + list2_size); m++){
		list1[m] = temp[m];
	}
	
}


void merge_sort(int arr[], int len){
	if (len > 1){
		int *list1 = arr;
		int list1_size = len/2;
		int *list2 = arr + len/2;
		int list2_size = len - list1_size;
		
		merge_sort(list1, list1_size);
		merge_sort(list2, list2_size);
		
		merge(list1, list1_size, list2, list2_size);
	}
}


int main(void){
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	merge_sort(a, 10);

	printf("排序后的结果是：");
	for( i=0; i < 10; i++ )
	{
		printf("%3d", a[i]);
	}
	printf("\n");

	return 0;
}
