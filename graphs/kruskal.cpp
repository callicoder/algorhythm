#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 50;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

viii G, MST;
vi parent(MAX);
vi rank(MAX);
int n;

int MakeSet(int x)
{
	parent[x] = x;
	rank[x] = 0;
}

int Find(int x)
{
	if(parent[x] != x)
		parent[x] = Find(parent[x]);
	return parent[x];
}

void Union(int x, int y)
{
	int xRoot = Find(x);
	int yRoot = Find(y);

	if(xRoot == yRoot)
		return;

	if(rank[xRoot] < rank[yRoot])
		parent[xRoot] = yRoot;
	else
	{
		parent[yRoot] = xRoot;
		if(rank[xRoot] == rank[yRoot])
			rank[xRoot]++;
	}
}

void kruskal()
{
	sort(G.begin(), G.end());
	for(viii::iterator it = G.begin(); it != G.end(); ++it)
	{
		int u = (it->second).first;
		int v = (it->second).second;
		int w = (it->first);

		int x = Find(u);
		int y = Find(v);

		if(x != y)
		{
			MST.push_back(iii(w,ii(u,v)));
			Union(x,y);
		}
	}
}

void printMinSpanningTree()
{
	printf("Edges in the minimum spanning tree : \n");
	for(viii::iterator it = MST.begin(); it != MST.end(); ++it)
	{
		printf("(%d,%d) : %d\n", (it->second).first, (it->second).second, it->first);
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
		G.push_back(iii(w, ii(u,v)));
	}
	kruskal();
	printMinSpanningTree();
	return 0;
}
