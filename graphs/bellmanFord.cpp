/*
	Time Complexity : O(|V|*|E|)
*/
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
enum{NIL = -1, MAX = 50, INF = 9999};

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;

viii G;
vi dist(MAX);
vi parent(MAX);
int n,m;

inline void initializeSingleSource(int s)
{
	for(int u = 0; u < n; u++)
	{
		dist[u] = INF;
		parent[u] = NIL;
	}
	dist[s] = 0;
}

inline void relaxEdge(int u, int v, int w)
{
	if(dist[v] > dist[u] + w)
	{
		dist[v] = dist[u] + w;
		parent[v] = u;
	}
}

bool bellmanFord(int s)
{
	initializeSingleSource(s);

	for(int i = 1; i <= n-1; i++)
	{
		for(viii::iterator it = G.begin(); it != G.end(); ++it)
		{
			int u = (it->first).first;
			int v = (it->first).second;
			int w = it->second;
			
			relaxEdge(u,v,w);
		}
	}

	for(viii::iterator it = G.begin(); it != G.end(); ++it)
    {
    	int u = (it->first).first;
        int v = (it->first).second;
        int w = it->second;

		if(dist[v] > dist[u] + w)
			return true;
	}
	return false;
}

void printPath(int s, int t)
{
    if(t == s)
        printf("%d ",s);
    else
    {
        printPath(s, parent[t]);
        printf("%d ",t);
    }
}

int main()
{
	scanf("%d %d",&n,&m);
	int u,v,w;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		G.push_back(iii(ii(u,v),w));
	}
	int s,t;
	scanf("%d %d",&s,&t);
	bool isNegativeWtCycle = bellmanFord(s);	
	if(isNegativeWtCycle)
		printf("The graph contains negative weight cycle\n");
	else
		printPath(s,t);
	return 0;
}
