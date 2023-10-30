#include <stdio.h>
#define SIZE 5

void insert(int x, int n, int arr[])			// Insertion Sort Algorithm
{
	int i,j;
	for(i=0; i<n; i++)
	{
		if(arr[i]>=x)				// ���� ���Ե� x�� ���ĵ� ����Ʈ �� �ּҰ����� �۰ų� ���� �� 
		{
			for(j=n-1; j>=i; j--)
				arr[j] = arr[j-1];				// ���ĵ� ����Ʈ�� ���� �ִ밪���� ���������� �� ĭ�� �ű�. 
			
			arr[i] = x;						// ���� ������ x�� ��ġ�� �°� �־���. 
			break;
		}
	}
}

int main(void)
{
	int a[SIZE] = {82, 61, 5, 30, 74};		// unsorted array 
	
	for(int k=1; k<SIZE; k++)				// a[1](61)���� �� ���� ���ҿ� ��
		insert(a[k], k+1, a);				// insert function
	
	for(int k=0; k<SIZE; k++)
		printf("%d ", a[k]);					// print sorted array
	
	return 0;
}
