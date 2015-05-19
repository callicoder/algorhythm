#include<iostream>
using namespace std;
int main() {
	int m;
	cin >> m;
	int S[m];
	for(int i = 0; i < m; i++) {
		cin >> S[i];
	}
	int N;
	cin >> N;
	int count[N+1][m];
	
	for(int i = 0; i < m; i++) {
		count[0][i] = 1;
	}

/*
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < m; j++) {
			// Count of solutions including S[j]
			int x = i-S[j] >= 0 ? count[i-S[j]][j]: 0;

			// Count of solutions excluding S[j]
			int y = j >= 1 ? count[i][j-1]: 0;
			
			// Total Count
			count[i][j] = x + y;
		}
	}

*/
	for(int j = 0; j < m; j++) {
		for(int i = 1; i <= N; i++) {
			// Count of solutions including S[j]
			int x = i-S[j] >= 0 ? count[i-S[j]][j]: 0;

			// Count of solutions excluding S[j]
			int y = j >= 1 ? count[i][j-1]: 0;
			
			// Total Count
			count[i][j] = x + y;
		}
	}

	cout << count[N][m-1] << endl;
	return 0;
}