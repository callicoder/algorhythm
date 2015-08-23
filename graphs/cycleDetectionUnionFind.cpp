#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 50;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii G;
vi parent(MAX);
int n;

int Find(int x)
{
	if(parent[x] == x)
		return x;
	else
		return Find(parent[x]);	
}

void Union(int x, int y)
{
	int xRoot = Find(x);
	int yRoot = Find(y);
	parent[xRoot] = yRoot;
		
}

inline void MakeSet(int x)
{
	parent[x] = x;
}

bool isCycle()
{
	for(int v = 0; v < n; v++)
		MakeSet(v);
	for(vii::iterator it = G.begin(); it != G.end(); ++it)
	{
		int u = it->first;
		int v = it->second;
		
		int x = Find(u);
		int y = Find(v);

		if(x == y)
			return true;
		else
			Union(x,y);
	}
	return false;
}

int main()
{
	int m;
	scanf("%d %d",&n,&m);
	int u,v;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&u,&v);
		G.push_back(ii(u,v));
	}
	
	if(isCycle())
		printf("The graph contains a cycle\n");
	else
		printf("The graph doesn't contain a cycle\n");

	return 0;
}

