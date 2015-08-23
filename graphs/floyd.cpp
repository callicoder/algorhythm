#include<cstdio>
using namespace std;
const int MAX = 20;
const int INF = 9999;
 
int weight[MAX][MAX];
int dist[MAX][MAX];
int n;

void floyd()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			dist[i][j] = weight[i][j];

	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

void printShortestDistMatrix()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int m;
	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			weight[i][j] = (i == j)?0:INF;

	int u,v,w;	
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		weight[u][v] = w;	
	}		
	floyd();
	printShortestDistMatrix();
	return 0;
}
