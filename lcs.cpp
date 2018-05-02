#include <iostream>
#include <cstring>
using namespace std;

int max (int a, int b) {
	return (a > b) ? a : b;
}

int lcs (char* a, char* b, int m, int n) {
	if (m == 0 || n == 0) {
		return 0;
	}

	if (a[m-1] == b[n-1]) {
		return 1+lcs(a, b, m-1, n-1);
	} else {
		return max(lcs(a, b, m, n-1), lcs(a, b, m-1, n));
	}
}

int main() {
	char a[] = "sambhav";
	char b[] = "vaibhav";
	
	int m = strlen(a), n = strlen(b);
	
	cout << lcs(a, b, m, n) << endl;
	
	return 0;
}
