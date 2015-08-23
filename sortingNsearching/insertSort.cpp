/*
	Time Complexity :

	Best case : O(n)
	Average Case : O(n^2)
	Worst Case : O(n^2)

	Max. swaps required : O(n^2)
*/

#include<cstdio>
const int MAX = 50;

void insertSort(int a[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i-1;
		while(j >= 0 && key < a[j])	
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = key;		
	}
}


int main()
{
	int a[MAX], n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	
	insertSort(a, n);

	printf("Sorted Array : \n");
	for(int i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");	
	return 0;
}
