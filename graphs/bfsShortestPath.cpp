#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 50;
enum{WHITE,GRAY,BLACK,NIL = -1,INF = 9999};
vector< vector<int> > G(MAX);
vector<int> color(MAX);
vector<int> dist(MAX);
vector<int> parent(MAX);
int n;

void printPath(int s, int v)
{
	if(v == s)
		printf("%d ",s);
	else if(v == NIL)
		printf("not path from %d to %d exists\n",s,v);
	else
	{
		printPath(s, parent[v]);
		printf("%d ",v);
	}
}	

void bfs()
{
	for(int u = 0; u < n; u++)
	{
		color[u] = WHITE;
		dist[u] = INF;
		parent[u] = NIL;
	}	
	int s = 0;
	color[s] = GRAY;
	dist[s] = 0;
	parent[s] = NIL;
	
	queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for(vector<int>::iterator  it = G[u].begin(); it != G[u].end(); ++it)
		{
			int v = *it;
			if(color[v] == WHITE)
			{
				color[v] = GRAY;
				dist[v] = dist[u] + 1;
				parent[v] = u;
				Q.push(v);
			}
		}
		color[u] = BLACK;
	}
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
	int source, dest;
	scanf("%d %d",&source, &dest);
	printPath(source, dest);
	return 0;
}
