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

	int ways[N+1];
	for(int i = 0; i <= N; i++) {
		ways[i] = 0;
	}

	ways[0] = 1;

	for(int i = 0; i < m; i++) {
		for(int j = S[i]; j <= N; j++) {
			ways[j] += ways[j-S[i]];
			cout << j << " " << ways[j] << endl;
		}
	}

	cout << ways[N] << endl;
	return 0;
}