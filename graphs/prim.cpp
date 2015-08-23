/*
	Time Complexity :
	1. Prim's algorithm using a 
	   binary min heap as priority queue :
			O(|V| + |E|)*log|V|  = O(|E|log|V|)

	2. prim's algorithm using a
	   fibonacci min heap as a priority queue :
			O(|E| + |V|log|V|)
		
*/
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;

enum{MAX = 50, NIL = -1, INF = INT_MAX};

int G[MAX][MAX];
int n;

// Function to print the constructed MST stored in parent[]
void printMST(int parent[])
{
	printf("Edge   Weight\n");
	for(int i = 1; i < n; i++)
		printf("%d - %d   %d\n", parent[i], i, G[i][parent[i]]);
}

// Function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[] )
{
	int min = INF; 
	int minIndex;
	for(int v = 0; v < n; v++)
	{
		if(mstSet[v] == false && key[v] < min)
		{
			min = key[v];
			minIndex = v;
		}
	}
	return minIndex;
}

void primMST()
{
	int key[n];
	int parent[n];
	bool mstSet[n];

	for(int v = 0; v < n; v++)
	{
		key[v] = INF;
		parent[v] = NIL;
		mstSet[v] = false;
	}
	key[0] = 0;
	
	// MST will have n-1 edges and n vertices	
	for(int count = 0; count < n-1; count++)
	{
		// Pick the minimum key vertex from the set of vertices
        // not yet included in MST
		int u = minKey(key, mstSet);
		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
		for(int v = 0; v < n; v++)
		{
			if(G[u][v] && mstSet[v] == false && G[u][v] < key[v])
			{
				key[v] = G[u][v];
				parent[v] = u;
			}
		}
	}		
	printMST(parent);
}	

int main()
{
	int m;
	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			G[i][j] = 0;

	int u,v,w;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		G[u][v] = G[v][u] = w;
	}
	primMST();
	return 0;
}	
