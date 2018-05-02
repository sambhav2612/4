#include <iostream>
using namespace std;

int count = 0;

void heapify(int array[], int n, int i) {
	int left = 2*i+1;
	int right = 2*i+2;
	int largest = i;
	
	if (left < n && array[left] > array[largest]) {
		largest = left;
	} else {
		largest = i;
		if (left < n) {
			++count;
		}
	}
	
	if (right < n && array[right] > array[largest]) {
		largest = right;
	} else {
		largest = i;
		if (right < n) {
			++count;
		}
	}
	
	if (largest != i) {
		swap(array[largest], array[i]);
		heapify(array, n, largest);
	}
}

void buildMaxHeap(int array[], int n) {
	for (int i = n/2-1; i >= 0; --i) {
		heapify(array, n, i);
	}
}

void sort (int array[], int n) {
	buildMaxHeap(array, n);
	
	for (int i = n-1; i >= 0; --i) {
		swap(array[0], array[i]);
		heapify(array, i, 0);
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
	
	sort(array, n);
	
	cout << "\nSorted\n";
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}
	
	return 0;
}
