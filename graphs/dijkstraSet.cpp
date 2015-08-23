#include<cstdio>
#include<vector>
#include<set>
using namespace std;
enum{NIL = -1, MAX = 50, INF = 9999};
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii G(MAX);
vi dist(MAX);
vi parent(MAX);
int n;

void dijkstra(int s)
{
	for(int u = 0; u < n; u++)
	{
		dist[u] = INF;
		parent[u] = NIL;
	}
	dist[s] = 0;
	set<ii> S;
	S.insert(ii(dist[s],s));
	while(!S.empty())
	{
		ii top = *S.begin();		
		S.erase(S.begin());
		int u = top.second;

		for(vii::iterator it = G[u].begin(); it != G[u].end(); ++it)
		{
			int v = it->first;
			int w = it->second;
			
			if(dist[v] > dist[u] + w)
			{
				if(dist[v] != INF)
					S.erase(S.find(ii(dist[v],v)));

				dist[v] = dist[u] + w;
				parent[v] = u;
				S.insert(ii(dist[v],v));
			}
		}
	}			
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
	int m;
	scanf("%d %d",&n,&m);
	int u,v,w;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		G[u].push_back(ii(v,w));
		G[v].push_back(ii(u,w));
	}
	int s,t;
	scanf("%d %d",&s,&t);
	dijkstra(s);
	printPath(s,t);
	printf("\n");
	dijkstra(s);
	
	return 0;
}
