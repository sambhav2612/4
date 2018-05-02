#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucket(float array[], int n) {
	vector<float> bucket[n];
	
	for (int i = 0; i < n; +i) {
		int bucketIndex = n*array[i];
		bucket[bucketIndex].push_back(array[i]);
	}
	
	for (int i = 0; i < n; ++i) {
		sort(bucket[i].begin(), bucket[i].end());
	}
	
	int index = 0;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < bucket[i].size(); ++j) {
			array[index++] = bucket[i][j];
		}
	}
}

int main() {
	int n = 0;
	cin >> n;
	
	float array[n] = {0.0};
	
	for (int i = 0; i < n; ++i) {
		cin >> array[i];
	}

	cout << "Unsorted\n";
	for (int i = 0; i < n; ++i) {
		cout << array[i] << endl;
	}

	bucket(array, n);

	cout << "\nSorted\n";
	for (int i = 0; i < n; ++i) {
		cout << array[i] << endl;
	}

	return 0;
}
