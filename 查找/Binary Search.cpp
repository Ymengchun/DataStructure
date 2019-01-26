#include <stdio.h>

int Binary_Search(int a[], int length, int key){
	int low, high, mid;
	low = 0;
	high = length - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if (a[mid] < key)
			low = mid + 1;
		else if (a[mid] > key)
			high = mid - 1;
		else
			return mid;		
	}
	return -1;
}

int main(void){
	int result;
	int a[] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
	
	result = Binary_Search(a, 11, 88);
	printf("二分查找的结果: %d\n", result);
	
	return 0;
}
