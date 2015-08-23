/*
	Time Complexity : O(|V| + |E|)
*/

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 50;
vector< vector<int> > G(MAX);
vector<bool> visited(MAX);
int n;

void bfs_visit(int s)
{
	printf("%d ",s);
	visited[s] = true;	
	queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it)
		{
			int v = *it;
			if(visited[v] == false)
			{
				printf("%d ",v);
				visited[v] = true;
				Q.push(v);
			}
		}
	}
}

void bfs()
{
	for(int u = 0; u < n; u++)
		visited[u] = false;

	for(int u = 0; u < n; u++)
		if(visited[u] == false)
			bfs_visit(u);
}

int main()
{
	int m;
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs();
	return 0;
}
