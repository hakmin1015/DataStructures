#include <stdio.h>
#define SIZE 5

void swap(int *A, int *B)         // call by reference
{
	int tmp;
	tmp = *A;
	*A = *B;
	*B = tmp;
}

int select_min(int start, int end, int arr[])		// Selection Sort Algorithm
{
	int min_idx = start;
	for(int i=start+1; i<=end; i++)
	{
		if(arr[i]<arr[min_idx])
			min_idx = i;
	}
	
	return min_idx;
}

int main(void)
{
	int a[SIZE] = {82, 61, 5, 30, 74};		// unsorted array 
	
	int i;
	int min_idx;
	for(i=0; i<SIZE-1; i++)
	{
		min_idx = select_min(i,SIZE-1, a);
		swap(&a[i], &a[min_idx]);
	}
	
	for(int k=0; k<SIZE; k++)
		printf("%d ", a[k]);					// print sorted array
	
	return 0;	
}
