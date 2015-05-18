#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
/*

LCS[m][n] = Longest common subsequence between strings s[1..m] and t[1..n]

LCS[i][j] = Longest common subsequence between prefixes s[1..i] and t [1..j]

LCS[i][j] = LCS[i-1][j-1] + 1				;if s[i] == t[j]
		  = max(LCS[i][j-1], LCS[i-1][j])	;if s[i] != t[j]

*/


int main() {
	string s, t;
	cin >> s >> t;
	int m = s.length();
	int n = t.length();

	int lcs[m][n];
	for(int i = 0; i <= m; i++) {
		lcs[i][0] = 0;
	}

	for(int j = 0; j <= n; j++) {
		lcs[0][j] = 0;
	}
		
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[i-1] == t[j-1]) {
				lcs[i][j] = lcs[i-1][j-1] + 1;
			} else {
				lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
			}
		}
	}
	cout << endl;
	cout << lcs[m][n] << endl;
	return 0;
}