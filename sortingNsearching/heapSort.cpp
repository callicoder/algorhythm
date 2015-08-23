/*

	Time Complexity :

	Build MaxHeap : O(n)
	
	Heap Sort : 	
	Best Case : O(n*log(n))
	Average Case : O(n*log(n))
	Worst Case : O(n*log(n))

*/

#include<cstdio>
#include<algorithm>
using namespace std;
#define LEFT(i) 2*(i)
#define RIGHT(i)  2*(i) + 1

const int MAX = 50;
int heapSize;

void maxHeapify(int A[], int n, int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;
	
	if(l <= heapSize && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if(r <= heapSize && A[r] > A[largest])
		largest = r;
	if(largest != i)
	{
		swap(A[i], A[largest]);
		maxHeapify(A, n, largest);
	}
}

void buildMaxHeap(int A[], int n)
{
	heapSize = n;
	for(int i = n/2; i >= 1; i--)
		maxHeapify(A, n, i);
}

void heapSort(int A[], int n)
{
	buildMaxHeap(A, n);
	for(int i = n; i >= 2; i--)
	{
		swap(A[1], A[i]);
		heapSize--;
		maxHeapify(A, n, 1);
	}
}

int main()
{
	int A[MAX], n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&A[i]);
	
	heapSort(A, n);

	for(int i = 1; i <= n; i++)
		printf("%d ",A[i]);	
	printf("\n");
	return 0;
}
