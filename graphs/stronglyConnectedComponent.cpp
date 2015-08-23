#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

const int MAX = 50;
vector< vector<int> > G(MAX);
vector< vector<int> > GT(MAX);
vector<bool> visited(MAX);
stack<int> S;
int n;

void dfs_visit_original(int u)
{
	visited[u] = true;
	for(int v = 0; v < G[u].size(); v++)
		if(visited[G[u][v]] == false)
			dfs_visit_original(G[u][v]);
	S.push(u);
}

void dfs_original()
{
	for(int u = 0; u < n; u++)
		visited[u] = false;
	for(int u = 0; u < n; u++)
		if(visited[u] == false)
			dfs_visit_original(u);
}

void dfs_visit_transpose(int u)
{
    visited[u] = true;
	printf("%d ",u);
    for(int v = 0; v < GT[u].size(); v++)
        if(visited[GT[u][v]] == false)
            dfs_visit_transpose(GT[u][v]);
}

void dfs_transpose()
{
    for(int u = 0; u < n; u++)
        visited[u] = false;
	printf("The SCCs are : \n");
    while(!S.empty())
	{
		int u = S.top();
		S.pop();
        if(visited[u] == false)
		{
            dfs_visit_transpose(u);
			printf("\n");
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
		GT[v].push_back(u);
	}
	dfs_original();
	dfs_transpose();
	return 0;
}	
		
	
