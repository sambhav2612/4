#include <iostream>
using namespace std;

void selection (int array[], int n) {
	int min = 0;
	for (int i = 0; i < n; ++i) {
		min = i;
		for (int j = i+1; j < n; ++j) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		
		// swap array[min] with array[i]
		swap(array[i], array[min]);
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
	
	selection(array, n);
	
	cout << "\nSorted" << endl;
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}
}
