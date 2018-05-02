#include <algorithm>
using namespace std;

int* maxEle (int array[], int n) {
	return max_element(array, array+n);
}

void counting (int array[], int n, int exp) {
	int final[n] = {0};
	int *max = max_element(array, array+n);
	
	int count[*max+1] = {0};
	int i = 0;
	
	// count of all in the provided array
	for (i = 0; i < n; ++i) {
		++count[(array[i]/exp)%10];
	}
	
	// count of elements less than equal to than current
	for (i = 1; i < *max+1; ++i) {
		count[i] += count[i-1];
	}
	
	for (i = n-1; i >= 0; --i) {
		final[count[(array[i]/exp)%10]-1] = array[i];
		--count[(array[i]/exp)%10];
	}
	
	for (i = 0; i < n; ++i) {
		array[i] = final[i];
	}
	
}
