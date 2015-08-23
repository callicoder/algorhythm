#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 50;
vector< vector<int> > G(MAX);
vector<int> partition(MAX);
int n;

void bfs(int s)
{
	for(int u = 0; u < n; u++)
		partition[u] = 0;
	partition[s] = 1;	
	queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it)
		{
			int v = *it;
			if(partition[v] == 0)
			{
				partition[v] = 3 - partition[u];
				Q.push(v);
			}
			else if(partition[v] == partition[u])
            {
                printf("The graph is not bipartite\n");
                return;
            }
		}
	}
	printf("The graph is bipartite\n");
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
	bfs(0);
	return 0;
}
