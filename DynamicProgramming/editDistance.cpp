#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

#define UNKNOWN -1
/*

ED[m][n] = Minimum number of edits required to convert a[1..m] to b[1..n]

ED[i][j] = Minimum number of edits required to convert a[1..i] to b[1..j]

ED[i][0] = W(del(a[k]));	1 <= k <= i;

ED[0][j] = W(ins(b[k]));	1 <=k <= j;

ED[i][j] = ED[i-1][j-1]		;if a[i] = b[j]
		 
		 = min( ED[i-1][j-1] + W(sub(a[i], b[j])),			;if a[i] != b[j] 

		 		ED[i-1][j] + W(del(a[i])), 
		 	
		 		ED[i][j-1] + W(ins(b[j])) 
		 	)

*/
int min(int a, int b, int c) {
	int minimum = a<b?a:b;
	minimum = minimum<c?minimum:c;
	return minimum;
}

int main() {
	string a, b;
	cin >> a >> b;
	int m =  a.length();
	int n = b.length();
	
	int ED[m+1][n+1];

	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			ED[i][j] = UNKNOWN;
		}
	} 
	
	for(int i = 0; i <= m; i++) {
		ED[i][0] = i;
	}

	for(int j = 0; j <= n; j++) {
		ED[0][j] = j;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i-1] == b[j-1]) {
				ED[i][j] = ED[i-1][j-1];
			} else {
				ED[i][j] = min(ED[i-1][j-1] + 1, ED[i][j-1] + 1, ED[i][j-1] + 1);
			}
		}
	}

	cout << ED[m][n] << endl;
	return 0;
}