#include <iostream>

using namespace std;

int findInRotatedArray(int A[], int n, int key) {
	int L = 0;
	int R = n-1;
	int middle;
	while(left <= right) {
		middle = ( left + right ) / 2;
		if(A[middle] == key)
			return middle;
		if(A[left] < A[middle]) {
			if(A[left] <= key && key <= A[middle])
				right = middle;
			else
				left = middle;
		}
		else {
			if(A[middle] <= key && key <= A[right])
				left = middle;
			else
				right = middle;
		}
	}
	return -1;
}

