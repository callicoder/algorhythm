#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

const int MAX = 50;
enum{WHITE, GRAY, BLACK, NIL = -1};
vector< vector<int> > G(MAX);
vector<int> color(MAX);
vector<int> parent(MAX);
int n;

void dfs_visit(int u)
{
	color[u] = GRAY;
	for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it)
	{
		int v = *it;
		if(color[v] == WHITE)
		{
			parent[v] = u;
			dfs_visit(v);
		}
		else if(color[v] == GRAY)
		{
			if(v != parent[u])
			{
				printf("Graph contains a cycle : \n");
				int x = u;
				do
				{
					printf("%d->",x);
					x = parent[x];
				}while(x != v);
				printf("%d\n",x);
			}		
		}
	}	
	color[u] = BLACK;
}

void dfs()
{
	for(int u = 0; u < n; u++)
	{
		color[u] = WHITE;
		parent[u] = NIL;
	}
	for(int u = 0; u < n; u++)
	{
		if(color[u] == WHITE)
		{
			dfs_visit(u);
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
		
	
