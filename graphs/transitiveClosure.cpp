#include<cstdio>
const int MAX = 50;
bool adj[MAX][MAX];
bool reachable[MAX][MAX];
int n;

void transitiveClosure()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			reachable[i][j] = adj[i][j];

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
	
}

void printReachabilityMatrix()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ",reachable[i][j]);
		printf("\n");
	}
}

int main()
{
	int m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			adj[i][j] = 0;
	int u,v;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&u,&v);
		adj[u][v] = 1;
	}
	transitiveClosure();
	printReachabilityMatrix();
	return 0;
}
	
