/*
	Time Complexity :  O(d*(n+b))
	d = number of digits in input integers
	b = base for representing numbers, for ex, for decimal system, b is 10 
		b is equal to the range k, since here we are using counting sort on 
		individual digits
*/

#include<cstdio>
#include<algorithm>
using namespace std;

void countSort(int A[], int n, int exp)
{
	int output[n];
	int count[10] = {0};

	for(int i = 0; i < n; i++)
	{
		count[(A[i]/exp)%10]++;
	}

	for(int i = 1; i < 10; i++)
	{
		count[i] += count[i-1];
	}

	for(int i = 0; i < n; i++)
	{
		output[count[(A[i]/exp)%10]-1] = A[i];
		count[(A[i]/exp)%10]--;
	}
	
	for(int i = 0; i < n; i++)
		A[i] = output[i];
}

void radixSort(int A[], int n)
{
	// Find the maximum number to know number of digits
    int m = *max_element(A, A+n);

	// Do counting sort for every digit. Note that instead of passing digit number,
    // exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(A, n, exp);
}

int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i = 0; i < n; i++)
		scanf("%d",&A[i]);
	radixSort(A, n);
	printf("Sorted Array : \n");
	for(int i = 0; i < n; i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}
	
