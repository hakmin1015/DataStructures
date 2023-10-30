#include <stdio.h>
#define SIZE 5

void swap(int &A, int &B)         // call by reference
{
	int tmp;
	tmp = A;
	A = B;
	B = tmp;
}

int main(void)
{
	int a[SIZE] = {82, 61, 5, 30, 74};		// unsorted array 
	
	int i,j;
	for(i=0; i<SIZE-1; i++)					// Bubble Sort Algorithm
	{
		for(j=SIZE-1; j>i; j--)
		{
			if(a[j-1] > a[j])			// 왼쪽 원소가 오른쪽 원소보다 크면 swap 실행 
				swap(a[j-1], a[j]);
		}
	}
	
	for(int k=0; k<SIZE; k++)
		printf("%d ", a[k]);				// print sorted array
	
	return 0;
}
