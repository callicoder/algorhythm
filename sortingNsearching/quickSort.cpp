/*
	Time Complexity :
	
	Best Case : O(n*log(n))
	Average Case : O(n*log(n))
	Wors Case : O(n^2)

*/
#include<cstdio>
const int MAX = 50;

int partition(int a[], int p, int r)
{
	int key = a[p];
	int i = p, j = r;
	while(a[i] <= key && i < r)
		i++;
	while(a[j] > key)
		j--;
	if(i < j)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	else
	{
		a[p] = a[j];
		a[j] = key;
	}
	return j;
}

void quickSort(int a[], int p, int r)
{
	if(p < r)
	{
		int q = partition(a, p, r);
		quickSort(a, p, q-1);
		quickSort(a, q+1, r);
	}
}


int main()
{
	int a[MAX], n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);

	quickSort(a, 0, n-1);

	printf("Sorted Array : \n");
	for(int i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");	
	return 0;
}
