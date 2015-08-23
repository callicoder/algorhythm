/*
	Running Time : O(|V| + |E|)
*/
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

const int MAX = 50;
vector< vector<int> > G(MAX);
vector<bool> visited(MAX);
int n;

void dfs_visit_iterative(int u)
{
	stack<int> S;
	S.push(u);
	while(!S.empty())
	{
		u = S.top();
		S.pop();
		if(visited[u] == false)
		{
			printf("%d ",u);
			visited[u] = true;
			for(int v = 0; v < G[u].size(); v++)
				S.push(G[u][v]);
		}
	}
}

void dfs_visit(int u)
{
	printf("%d ",u);
	visited[u] = true;
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
	for(int u= 0; u < n; u++)
	{
		if(visited[u] == false)
		{
			dfs_visit(u);
		//	dfs_visit_iterative(u);
		}
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
		
	
