#include <iostream>
using namespace std;

void bubble (int array[], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n-i-1; ++j) {
			if (array[j] > array[j+1]) {
				swap(array[j], array[j+1]);
			}
		}
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
	
	bubble(array, n);
	
	cout << "Sorted" << endl;
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}
}
