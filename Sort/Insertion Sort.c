#include <stdio.h>
#define SIZE 5

void insert(int x, int n, int arr[])			// Insertion Sort Algorithm
{
	int i,j;
	for(i=0; i<n; i++)
	{
		if(arr[i]>=x)				// 새로 삽입될 x가 정렬된 리스트 중 최소값보다 작거나 같을 때 
		{
			for(j=n-1; j>=i; j--)
				arr[j] = arr[j-1];				// 정렬된 리스트의 값을 최대값부터 오른쪽으로 한 칸씩 옮김. 
			
			arr[i] = x;						// 새로 삽입할 x를 위치에 맞게 넣어줌. 
			break;
		}
	}
}

int main(void)
{
	int a[SIZE] = {82, 61, 5, 30, 74};		// unsorted array 
	
	for(int k=1; k<SIZE; k++)				// a[1](61)부터 맨 왼쪽 원소와 비교
		insert(a[k], k+1, a);				// insert function
	
	for(int k=0; k<SIZE; k++)
		printf("%d ", a[k]);					// print sorted array
	
	return 0;
}
