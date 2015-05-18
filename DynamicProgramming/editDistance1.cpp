#include<iostream>
#include<string>
using namespace std;
#define UNKNOWN -1
#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLEN 100

typedef struct {
	int cost;
	int parent;
} cell;

void reconstructPath(cell T[][MAXLEN], string s, string t, int i, int j) {
	if(T[i][j].parent == UNKNOWN) {
		return;
	}

	if(T[i][j].parent == MATCH) {
		reconstructPath(T, s, t, i-1, j-1);
		// Match Out
		if(s[i-1] == t[j-1]) {
			cout << "M";
		} else {
			cout << "S";
		}
		return;
	}

	if(T[i][j].parent == INSERT) {
		reconstructPath(T, s, t, i, j-1);
		// Insert Out
		cout << "I";
		return;
	}

	if(T[i][j].parent == DELETE) {
		reconstructPath(T, s, t, i-1, j);
		// Delete out
		cout << "D";
		return;
	}
}


int main() {
	string s, t;
	cin >> s >> t;
	int m = s.length();
	int n = t.length();
	cell T[MAXLEN][MAXLEN];

	// init
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			T[i][j].cost = UNKNOWN;
			T[i][j].parent = UNKNOWN;
		}
	}

	// row_init
	for(int i = 0; i <= m; i++) {
		T[i][0].cost = i;
		T[i][0].parent = DELETE;
	}

	// column_init
	for(int j = 0; j <= n; j++) {
		T[0][j].cost = j;
		T[0][j].parent = INSERT;
	}

	// Boundary condition
	T[0][0].parent = UNKNOWN;

	int option[3];

	for(int i = 1 ; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[i-1] == t[j-1]) {
				option[MATCH] = T[i-1][j-1].cost;
			} else {
				option[MATCH] = T[i-1][j-1].cost + 1;
			}
			option[INSERT] = T[i][j-1].cost + 1;
			option[DELETE] = T[i-1][j].cost + 1;

			T[i][j].cost = option[MATCH];
			T[i][j].parent = MATCH;

			for(int k = INSERT; k <= DELETE; k++) {
				if(option[k] < T[i][j].cost) {
					T[i][j].cost = option[k];
					T[i][j].parent = k;
				}
			}
		}
	}

	cout << T[m][n].cost << endl;
	reconstructPath(T, s, t, m, n);
	cout << endl;
	return 0;
}