#include<cstdio>
const int MAX = 50;

int main()
{
	int a[MAX];
	int n;
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	printf("Enter the array : ");
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	
	return 0;
}
