#include <iostream>
using namespace std;

void insertion (int array[], int n) {
	for (int i = 1; i < n; ++i) {
		int j = i-1;
		int key = array[i];
		
		while (j >= 0 && array[j] > key) {
			array[j+1] = array[j];
			--j;
		}
		
		array[j+1] = key;
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
	
	insertion(array, n);
	
	cout << "\nSorted" << endl;
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}
}
