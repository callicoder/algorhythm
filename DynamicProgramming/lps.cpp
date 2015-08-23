#include <iostream>
#include <algorithm>
using namespace std;

/*

lps[i][j] = length of longest palindromic subsequence of s[i..j]

lps[i][i] = 1								; Every string of length 1 is a palindrom of length 1
lps[i][i+1] = 2								; Every string of length 2 is a palindrom of length 2
lps[i][j] = lps[i+1][j-1] + 2 				; if s[i] == s[j]
		  = max(lps[i+1][j], lps[i][j-1])	; if s[i] != s[j]

*/

int main() {
	string s;
	cin >> s;
	int n = s.length();
	int lps[n][n];
	for(int i = 0; i < n; i++) {
		lps[i][i] = 1;
		
		if(i == n-1) {
			continue;
		}

		lps[i][i+1] = 2;
	}

	for(int i = 0; i < n; i++) {
		for(int j = i+2; j < n; j++) {
			if(s[i] == s[j]) {
				lps[i][j] = lps[i+1][j-1] + 2;
			} else {
				lps[i][j] = max(lps[i+1][j], lps[i][j-1]);
			}
		}
	}

	cout  << lps[0][n-1] << endl;
	return 0;
}