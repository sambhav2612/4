// uses counting.h

#include <iostream>
#include "counting.h"
using namespace std;

void radix(int array[], int n) {
	int max = *maxEle(array, n);
	
	for (int i = 1; max/i > 0; i *= 10) {
		counting(array, n, i);
	}
}

int main() {
	int n;
	cin >> n;

	int array[n] = {0};

	for (int i = 0; i < n; ++i) {
		cin >> array[i];
	}

	cout << "Unsorted" << endl;
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}

	radix(array, n);

	cout << "Sorted" << endl;
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}
	
	return 0;
}
