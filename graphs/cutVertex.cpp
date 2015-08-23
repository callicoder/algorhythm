#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 50;
vector< vector<int> > G(MAX);
vector<int> visited(MAX);
vector<int> num(MAX);
vector<int> low(MAX);
vector<bool> isCutVertex(MAX);
int n;
int count;

/* 
cut vertex is also known as articulation point
*/ 

void dfs_visit(int u)
{
	visited[u] =  true;
	num[u] = ++count;
	low[u] = num[u];
	int subtrees = 0;
	for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it)
	{
		int v = *it;
		if(visited[v] == false)
		{
			subtrees++;
			dfs_visit(v);
			low[u] = min(low[u], low[v]);
			if(low[v] >= num[u])
			{
				if(num[u] == 1 && subtrees <= 1)
					continue;
				isCutVertex[u] = true;
			}	
		}
		else
		{
			low[u] = min(low[u], num[v]);
		}
	}	
}

void dfs()
{
	for(int u = 0; u < n; u++)
	{
		visited[u] = false;
		isCutVertex[u] = false;
		num[u] = 0;
	}
	count = 0;
	for(int u = 0; u < n; u++)
	{
		if(visited[u] == false)
			dfs_visit(u);
	}
	printf("\n");
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
	return 0;
}	
		
	
