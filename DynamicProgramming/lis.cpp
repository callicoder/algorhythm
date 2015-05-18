#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

#define UNKNOWN -1
/*

LIS[i] = Longest increasing subsequence ending at index i

LIS[0] = 1;
LIS[i] = 1 + MAX(L[j])	;where j < i and a[j] < a[i]
	   = 1				;otherwise

return MAX(LIS[i]) 	;0 <= i < n;

*/

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int lis[n];
	for(int i = 0; i < n; i++) {
		lis[i] = 1;
	}
	int pred[n];
	for(int i = 0; i < n; i++) {
		pred[i] = UNKNOWN;
	}

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(a[i] > a[j]) {
				if(lis[i] < lis[j] + 1) {
					lis[i] = lis[j] + 1;
					pred[i] = j; 
				}	
			}
		}
	}

	int *maxLis = max_element(lis, lis+n);
	int maxLisIndex = (maxLis - lis);
	
	cout << *maxLis << endl;
	for(int i = maxLisIndex; i != UNKNOWN; i = pred[i]) {
		cout << a[i] << " ";
	}	
	cout << endl;

	return 0;
}
