/*
	Time Complexity :

	Best Case : O(n)
	Average case : O(n^2)
	Worst Case : O(n^2)
*/

#include<cstdio>
const int MAX = 50;

void bubbleSort(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main()
{
	int a[MAX], n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	
	bubbleSort(a, n);

	printf("Sorted Array : \n");
	for(int i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");	
	return 0;
}
