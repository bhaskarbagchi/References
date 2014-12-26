#include <iostream>
#include <vector>

using namespace std;

int maxSumSubarray(vector<int> A) {
	int curr_sum = 0;
	int max_sum = 0;
	if(A.size() == 0) {
		return 0;
	}
	int size = A.size();
	curr_sum = max_sum = A[0];
	for(int i = 1; i < size; i++) {
		if(curr_sum < 0)
			curr_sum = A[i];
		else
			curr_sum += A[i];
		if(max_sum < curr_sum)
			max_sum = curr_sum;
	}
	return max_sum;
}

int main(int argc, char * argv[]) {
	vector<int> A;
	A.push_back(1);
	A.push_back(-2);
	A.push_back(3);
	A.push_back(10);
	A.push_back(-4);
	A.push_back(7);
	A.push_back(2);
	A.push_back(-5);
	for(int i = 0; i < A.size(); i++) {
		cout<<A[i]<<"  ";
	}
	cout<<endl;
	cout<<maxSumSubarray(A)<<endl;
}