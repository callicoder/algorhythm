/*
	Time Complexity :

	Best Case : O(n^2)
    Average case : O(n^2)
    Worst Case : O(n^2)

	Max swaps required : O(n)

*/
#include<cstdio>
const int MAX = 50;

void selectSort(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int small = a[i];
		int index = i;
		for(int j = i+1; j < n; j++)
		{
			if(a[j] < small)
			{
				small = a[j];
				index = j;
			}
		}
		a[index] = a[i];
		a[i] = small;
	}
}


int main()
{
	int a[MAX], n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);

	selectSort(a, n);

	printf("Sorted Array : \n");
	for(int i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");	
	return 0;
}
