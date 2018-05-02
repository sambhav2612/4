#include <iostream>
using namespace std;

void merge(int array[], int low, int mid, int high) {
	int i = 0, j = 0, l = 0;
	
	int n1 = mid - low + 1;
	int n2 = high - mid;
	
	int left[n1] = {0}, right[n2] = {0};
	
	for (int i = 0; i < n1; ++i) {
		left[i] = array[low+i];
	}
	
	for (int i = 0; i < n2; ++i) {
		right[i] = array[mid+1+i];
	}
	
	i = 0, j = 0, l = low;
	
	while (i<n1 && j<n2) {
		if (left[i] <= right[j]) {
			array[l] = left[i];
			++i;
		} else {
			array[l] = right[j];
			++j;
		}
		++l;
	}
	
	
	while (i<n1) {
		array[l] = left[i];
		++l; ++i;
	}
	
	while (j<n2) {
		array[l] = right[j];
		++l; ++j;
	}
}

void sort (int array[], int low, int high) {
	if (low < high) {
		int mid = (high+low-1)/2;
		
		sort(array, low, mid);
		sort(array, mid+1, high);

		merge(array, low, mid, high);
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

	sort(array, 0, n-1);
	
	cout << "\nSorted" << endl;
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
	}

	return 0;
}
