#include<iostream>
#include<numeric>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int m;
		cin >> m;
		int s[m];
		for(int i = 0; i < m; i++) {
			cin >> s[i];
		}
		int sum = accumulate(s, s+m, 0);

		bool subset[sum+1][m+1];
		for(int i = 0; i <= m; i++) {
			subset[0][i] = true;
		}

		for(int i = 1; i <= sum; i++) {
			subset[i][0] = false;
		}

		for(int i = 1; i <= sum; i++) {
			for(int j = 1; j <= m; j++) {
				subset[i][j] = subset[i][j-1];
				if(i - s[j-1] >= 0) {
					subset[i][j] = subset[i][j] || subset[i-s[j-1]][j-1];
				}
			}
		}

		int result = 0;
		for(int s = 0; s <= sum; s++) {
			if(subset[s][m]) {
				result += s;
			}
		}		
		cout << result << endl;
	}	
	return 0;
}