#include<cstdio>
#include<memory.h>
#define MAX 50

// Factorial Iterative
int factItr(int n)
{
	int fact = 1;
	for(int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}

// Factorial Recursive
int factRec(int n)
{
	if(n == 0)
		return 1;
	return n*factRec(n-1);
}

// combination using factorial iterative
int combination1(int n, int r)
{
	return factItr(n)/(factItr(r) * factItr(n-r));
}

// combination using factorial recursive
int combination2(int n, int r)
{
	return factRec(n)/(factRec(r) * factRec(n-r));
}

// combination iterative
// (using C[n][r] = C[n][n-r] and calculating all factorials by using the result
// of a lower factorial)
int combination3(int n, int r)
{
	int factn, factnr, factr;

	r = r < n-r ? r : n-r;

	factr = 1;
	for(int i = 1; i <= r; i++)
		factr *= i;

	factnr = factr;
	for(int i = r+1; i <= n-r; i++)
		factnr *= i;

	factn = factnr;
	for(int i = n-r+1; i <= n; i++)
		factn *= i;

	return factn/(factr * factnr);
}

// combination iterative C[n][r] = (n * (n-1) * .... * (n - r + 1))/r!

int combination4(int n, int r)
{
	int upperTerm = 1;
	for(int i = 0; i < r; i++)
		upperTerm *= (n-i);

	int lowerTerm = 1;
	for(int i = 1; i <= r; i++)
		lowerTerm *= i;	

	return upperTerm/lowerTerm;
}

// combination recursive
int combination5(int n, int r)
{
	if(n == r || r == 0)
		return 1;
	return combination5(n-1, r-1) + combination5(n-1, r);
}

// combination using memoization. Top down approach
int MemoizeC[MAX][MAX];
int combination6(int n, int r)
{
	if(n == r || r == 0)
		return 1;
	if(MemoizeC[n][r] == 0)
		MemoizeC[n][r] = combination6(n-1, r-1) + combination6(n-1, r);
	return MemoizeC[n][r];
}

// combination using DP. Bottom up approach
int combination7(int n, int r)
{
	int C[n+1][r+1];
	memset(C, 0, sizeof(int)*(n+1)*(r+1));
	C[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		C[i][0] = 1;
		for(int j = 1; j <= i; j++)
		{
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		} 
	}
	return C[n][r];
}

int main()
{
	int n;
	printf("Enter n : ");
	scanf("%d",&n);
	int r;
	printf("Enter r : ");
	scanf("%d",&r);
	memset(MemoizeC, 0, sizeof(int)*MAX*MAX);
	printf("C(n,r) = %d\n",combination6(n,r));
	return 0;
}
