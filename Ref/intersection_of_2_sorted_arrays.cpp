#include <iostream>
#include <vector>

using namespace std;

vector<int> findIntersection(vector<int> A, vector<int> B) {
	vector<int> intersection = new vector();
	int i = 0, j = 0;
	int sizeA = A.size();
	int sizeB = B.size();
	while(i<sizeA && j<sizeB) {
		if(A[i] == B[j]) {
			intersection.push_back(A[i]);
			i++; j++;
		} else if(A[i] < B[j]) {
			i++;
		} else {
			j++;
		}
	}
	return intersection;
}


int main(int argc, char* argv[]) {
	
	return 0;
}