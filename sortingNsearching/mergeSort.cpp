/*
	Time Complexity :

	Best case : O(n*log(n))
	Average case : O(n*log(n))
	Worst Case : O(n*log(n))

*/
#include<cstdio>
const int MAX = 50;
const int INF = 9999;

int merge(int a[], int p, int q, int r)
{
	int L[MAX];
	int n1 = q - p + 1;
	for(int i = 0; i < n1; i++)
		L[i] = a[p + i];
	L[n1] = INF;

	int R[MAX];
	int n2 = r - q;
	for(int j = 0; j < n2; j++)
		R[j] = a[q + j + 1];
	R[n2] = INF;

	int i = 0, j = 0;
	for(int k = p; k <= r; k++)
	{
		if(L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}
}

int mergeSort(int a[], int p, int r)
{
	if(p < r)
	{
		int q = (p+r)/2;
		mergeSort(a, p, q);
		mergeSort(a, q+1, r);
		merge(a, p, q, r);
	}
}

int main()
{
	int a[MAX], n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	
	mergeSort(a, 0, n-1);

	printf("Sorted Array : \n");
	for(int i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");	
	return 0;
}
