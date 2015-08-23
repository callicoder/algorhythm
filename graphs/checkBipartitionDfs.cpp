#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

const int MAX = 50;
enum{NONE, BLUE, GREEN};
vector< vector<int> > G(MAX);
vector<int> color(MAX);
int n;
bool isBipartite;

void dfs_visit(int u, int c)
{
	color[u] = c;
	for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it)
	{
		int v = *it;
		if(color[v] == NONE)
			dfs_visit(v, (c == BLUE)?GREEN:BLUE);
		else if(color[v] == color[u])
			isBipartite =  false;
	}	
}

void dfs()
{
	for(int u = 0; u < n; u++)
		color[u] = NONE;
	isBipartite = true;
	dfs_visit(0, BLUE);
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
	if(isBipartite)
		printf("The graph is bipartite\n");
	else
		printf("The graph is not bipartite\n");
	return 0;
}	
		
	
