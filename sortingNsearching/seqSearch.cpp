#include<cstdio>
const int MAX = 50;

int seqSearch(int a[], int n, int key)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == key)
			return i;
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
	
	int index = seqSearch(a, n, key);

	if(index == -1)
		printf("Key not found\n");
	else
		printf("Key found at index %d\n",index);

	return 0;
}
