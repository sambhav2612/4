#include <iostream>
#include <algorithm>
using namespace std;

void counting (int array[], int n) {
	int final[n] = {0};
	int *max = max_element(array, array+n);
	
	int count[*max+1] = {0};
	int i = 0;
	
	// count of all in the provided array
	for (i = 0; i < n; ++i) {
		++count[array[i]];
	}
	
	// count of elements less than equal to than current
	for (i = 1; i < *max+1; ++i) {
		count[i] += count[i-1];
	}
	
	for (i = n-1; i >= 0; --i) {
		final[count[array[i]]-1] = array[i];
		--count[array[i]];
	}
	
	for (i = 0; i < n; ++i) {
		array[i] = final[i];
	}
	
}

int main () {
	
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
	
	counting(array, n);
	
	cout << "\nSorted" << endl;
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}	
	
	return 0;
}
