#include<iostream>
#include<algorithm>
using namespace std;

/*

minCost[x][y] = minCost to reach (x,y) from (0,0)

minCost[0][0] = cost[0][0];
minCost[i][0] = minCost[i-1][0] + cost[i][0];
minCost[0][j] = minCost[0][j-1] + cost[0][j];
minCost[i][j] = min(minCost[i-1][j-1], minCost[i][j-1], minCost[i-1][j]) + cost[i][j]

*/

int minimum(int a, int b, int c) {
	int min = a<b?a:b;
	min = min<c?min:c;
	return min;
}

int main() {
	int m,n;
	cin >> m >> n;
	int cost[m][n];
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	int x,y;
	cin >> x >> y;

	int minCost[m][n];

	minCost[0][0] = cost[0][0];
	for(int i = 1; i < m; i++) {
		minCost[i][0] = minCost[i-1][0] + cost[i][0]; 
	}
	for(int j = 1; j < n; j++) {
		minCost[0][j] = minCost[0][j-1] + cost[0][j];
	}

	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			minCost[i][j] = minimum(minCost[i-1][j-1], minCost[i-1][j], minCost[i][j-1]) + cost[i][j];
		}
	}

	cout << minCost[x][y] << endl;
	return 0;
}