/*
	Time complexity : O(log(n))
*/

#include<cstdio>
const int MAX = 50;

int binSearchRec(int a[], int low, int high, int key)
{
	if(low > high)
		return -1;
	int mid = (low + high)/2;
	if(key == a[mid])
		return mid;
	else if(key < a[mid])
		return binSearchRec(a, low, mid-1, key);
	else
		return binSearchRec(a, mid+1, high, key);
}

int binSearch(int a[], int low, int high, int key)
{
	while(low <= high)
	{
		int mid = (low+high)/2;
		if(key == a[mid])
			return mid;
		else if(key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
			
int main()
{
	int a[MAX], n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	int key;
	scanf("%d",&key);

//	int index = binSearch(a, 0, n-1, key);
	int index = binSearchRec(a, 0, n-1, key);
	if(index == -1)
		printf("Key not found\n");
	else
		printf("Key found at index %d\n",index);

	return 0;
}
