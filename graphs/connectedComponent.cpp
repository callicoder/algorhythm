#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

const int MAX = 50;
vector< vector<int> > G(MAX);
vector<bool> visited(MAX);
vector<int> component(MAX);
int n;
int componentNum;

void dfs_visit(int u)
{
	visited[u] = true;
	component[u] = componentNum;
	for(int v = 0; v < G[u].size(); v++)
	{
		if(visited[G[u][v]] == false)
			dfs_visit(G[u][v]);
	}	
}

void dfs()
{
	for(int u = 0; u < n; u++)
		visited[u] = false;
	componentNum = 0;
	for(int u = 0; u < n; u++)
	{
		if(visited[u] == false)
		{
			componentNum = componentNum + 1;
			dfs_visit(u);
		}
	}
}

int main()
{
	int m;
	scanf("%d %d",&n, &m);
	int u,v;
	for(int i = 0; i < m; i ++)
	{	
		scanf("%d %d",&u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs();
	printf("Number of components = %d\n",componentNum);
	for(int c = 1; c <= componentNum; c++)
	{
		printf("vertices in component %d : \n",c);
		for(int i = 0; i < n; i++)
		{
			if(component[i] == c)
				printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}	
		
	
