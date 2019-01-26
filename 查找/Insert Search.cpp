#include <stdio.h>

int interpolation_search(int a[], int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n-1;
	while (low <= high)
	{
		mid = low + (key-a[low])/(a[high]-a[low])*(high-low);
		if (a[mid] < key)
			low = mid + 1;
		else if (a[mid] > key)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main(void)
{
	int result;
	int a[] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
	
	result = interpolation_search(a, 11, 88);
	printf("二分查找的结果: %d\n", result);
	
	return 0;
}
