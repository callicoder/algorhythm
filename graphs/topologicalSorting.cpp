/*
	Time Complexity :  O(|V| + |E|)
*/
#include<cstdio>
#include<vector>
#include<list>
using namespace std;

const int MAX = 50;
vector< vector<int> > G(MAX);
vector<bool> visited(MAX);
list<int> topoList;
int n;

void dfs_visit(int u)
{
	visited[u] = true;
	for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it)
	{
		int v = *it;
		if(visited[v] == false)	
			dfs_visit(v);
	}	
	topoList.push_front(u);
}

void dfs()
{
	for(int u = 0; u < n; u++)
		visited[u] = false;

	for(int u = 0; u < n; u++)
		if(visited[u] == false)
			dfs_visit(u);
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
	}
	dfs();
	printf("Topological sorting of vertices : \n");
	for(list<int>::iterator it = topoList.begin(); it != topoList.end(); ++it)
		printf("%d ",*it);
	printf("\n");
	return 0;
}	
		
	
