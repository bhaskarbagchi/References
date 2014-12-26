#include <iostream>
#include <climits>

using namespace std;

int minimum(int a, int b, int c, int d) {
	int l1 = (a < b) ? a : b;
	int l2 = (c < d) ? c : d;
	return (l1 < l2) ? l1 : l2;
}

int noOfCoins(int K) {
	if(K < 0)
		return INT_MAX;
	if(K == 1 || K == 3 || K == 9 || K == 10)
		return 1;
	else
		return minimum(noOfCoins(K-1), noOfCoins(K-3), noOfCoins(K-9), noOfCoins(K-10)) + 1;
}

int main(int argc, char* argv[]) {
	cout<<noOfCoins(15)<<endl;
	return 0;
}