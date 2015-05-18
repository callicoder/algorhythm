#include<iostream>
#include<algorithm>
#include<string>

#define UNKNOWN -1
#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLEN 100

using namespace std;

typedef struct {
	int length;
	int parent;
} cell;

void reconstructPath(cell lcs[][MAXLEN], string s, string t, int i, int j) {
	if(lcs[i][j].parent == UNKNOWN) {
		return;
	}

	if(lcs[i][j].parent == MATCH) {
		reconstructPath(lcs, s, t, i-1, j-1);
		cout << s[i-1];
	}

	if(lcs[i][j].parent == INSERT) {
		reconstructPath(lcs, s, t, i, j-1);
	}

	if(lcs[i][j].parent == DELETE) {
		reconstructPath(lcs, s, t, i-1, j);
	}
}

int main() {
	string s, t;
	cin >> s >> t;
	int m = s.length();
	int n = t.length();

	cell lcs[MAXLEN][MAXLEN];

	for(int i = 0; i <= m; i++) {
		lcs[i][0].length = 0;
	}

	for(int j = 0; j <= n; j++) {
		lcs[0][j].length = 0;
	}
		
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[i-1] == t[j-1]) {
				lcs[i][j].length = lcs[i-1][j-1].length + 1;
				lcs[i][j].parent = MATCH;
			} else {
				if(lcs[i][j-1].length > lcs[i-1][j].length) {
					lcs[i][j].length = lcs[i][j-1].length;
					lcs[i][j].parent = INSERT;
				} else {
					lcs[i][j].length = lcs[i-1][j].length;
					lcs[i][j].parent = DELETE;
				}
			}
		}
	}
	cout << lcs[m][n].length << endl;
	reconstructPath(lcs, s, t, m, n);
	cout << endl;
	return 0;
}