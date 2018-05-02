#include <iostream>
using namespace std;

int partition(int array[], int low, int high) {
	int pivot = array[high];
	int i = low-1;
	
	for (int j = low; j < high; ++j) {
		if (array[j] <= pivot) {
			// if a smaller element was ahead of pivot element
			i++;
			swap(array[i], array[j]);
		}
	}
	
	swap(array[i+1], array[high]);
	
	return (i+1);
}

void sort(int array[], int low, int high) {
	if (low < high) {
		int pivot = partition(array, low, high);
		
		// not including pivot becuase pivot would be in its correct position
		
		sort(array, low, pivot-1);
		sort(array, pivot+1, high);
	}
}

int main() {
	int n = 0;
	cin >> n;
	
	int array[n] = {0};
	
	for (int i = 0; i < n; ++i) {
		cin >> array[i];
	}
	
	cout << "Unsorted\n";
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}
	
	sort(array, 0, n-1);
	
	cout << "\nSorted\n";
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}
	
	return 0;
}
