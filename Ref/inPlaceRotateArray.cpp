// In place rotation yeilds reversing the array three times, 1 for whole array, 1 from index 0 to k and last one from k+1 to n-1

#include <iostream>
#include <vector>

using namespace std;

void reverseArray(int A[], int left, int right) {
	int temp;
	while(left <= right) {
		temp = A[left];
		A[left] = A[right];
		A[right] = temp;
		left++;
		right--;
	}
}

void inPlaceRotateArray(int A[], int size, int rotationKey) {
	reverseArray(A, 0, size-1);
	for(int i = 0; i < 7; i++) {
		cout<<A[i]<<"  ";
	}
	cout<<endl;
	reverseArray(A, 0, rotationKey-1);
	for(int i = 0; i < 7; i++) {
		cout<<A[i]<<"  ";
	}
	cout<<endl;
	reverseArray(A, rotationKey, size - 1);
	for(int i = 0; i < 7; i++) {
		cout<<A[i]<<"  ";
	}
	cout<<endl;
	
}

int main(int argc, char* argv[]) {
	int A[] = {1, 3, 6, 2, 10, 39, 87};
	for(int i = 0; i < 7; i++) {
		cout<<A[i]<<"  ";
	}
	cout<<endl;
	inPlaceRotateArray(A, 7, 3);
	// for(int i = 0; i < 7; i++) {
	// 	cout<<A[i]<<"  ";
	// }
	// cout<<endl;
	return 0;
}