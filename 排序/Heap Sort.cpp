#include <stdio.h>

swap(int arr[], int i, int j)
{
	int temp;
	
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void heap_adjust(int arr[], int i, int len)
{
	int left, temp;
	
	temp = arr[i];
	
	for(left = 2*i; left <= len; left *= 2)
	{
		if(left < len && arr[left] < arr[left+1])
		{
			left++;
		}
		
		if(temp >= arr[left])
		{
			break;
		}
		
		arr[i] = arr[left];
		i = left;
	}
	
	arr[i] = temp;
}

void heap_sort(int arr[], int len)
{
	int i;
	for(i = len/2; i > 0; i--)
	{
		heap_adjust(arr, i, len);
	}
	
	for(i = len; i > 1; i--)
	{
		swap(arr, 1, i);
		heap_adjust(arr, 1, i-1);
	}
}


int main(void)
{
	int i, arr[10] = {5,4,3,8,2,7,0,9,6,1};
	
	heap_sort(arr, 10);
	
	for(i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	
	return 0;
}
