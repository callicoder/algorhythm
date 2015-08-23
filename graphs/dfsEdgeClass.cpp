#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 50;
enum{WHITE, GRAY, BLACK};
vector< vector<int> > G(MAX);
vector<int> color(MAX);
vector<int> birth(MAX);
vector<int> death(MAX);
int n;
int timestamp;

/*
	In a depth-first search of an undirected graph G, every edge of G is either 
	a tree edge or a back edge.
	whereas in directed graphs all the 4 types of edges can occur.
*/

void dfs_visit(int u)
{
	color[u] = GRAY;
	birth[u] = ++timestamp;
	for(vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it)
	{
		int v = *it;
		if(color[v] == WHITE)	// birth[u] < birth[v] < death[v] < death[u]
		{
			printf("(%d -> %d) : tree edge\n", u, v);
			dfs_visit(v);
		}
		else if(color[v] == GRAY) // birth[v] <= birth[u] < death[u] <= death[v]
		{						  // self loops are back edges.
			printf("(%d -> %d) : back edge\n", u, v);
		}
		else
		{
			if(birth[u] < birth[v] < death[v] < death[u])
				printf("(%d -> %d) : forward edge\n", u, v);
			else if(birth[v] < death[v] < birth[u] < death[u])
				printf("%d -> %d : cross edge\n", u, v);
		} 
	}	
	color[u] = BLACK;
	death[u] = ++timestamp;
}

void dfs()
{
	for(int u = 0; u < n; u++)
	{
		color[u] = WHITE;
	}
	timestamp = 0;
	for(int u = 0; u < n; u++)
	{
		if(color[u] == WHITE)
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
		
	
