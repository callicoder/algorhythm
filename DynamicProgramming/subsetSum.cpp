#include<iostream>
using namespace std;

int main() {
	int m;
	cin >> m;
	int s[m];
	for(int i = 0; i < m; i++) {
		cin >> s[i];
	}
	int N;
	cin >> N;
	bool subset[N+1][m];
	for(int i = 0; i < m; i++) {
		subset[0][i] = true;
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < m; j++) {
			if(j == 0) {
				subset[i][j] = false;
			} else {
				subset[i][j] = subset[i][j-1];
				if(i - s[j] >= 0) {
					subset[i][j] = subset[i][j] || subset[i-s[j]][j-1];
				}
			}
		}
	}

	if(subset[N][m-1]) {
		cout << "Found a subset with given sum" << endl;	
	} else {
		cout << "No subset found with given sum" << endl;
	}
	return 0;
}