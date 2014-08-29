#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int noOfFactors(long long int n){
	if(n==1){
		return 1;
	}
	int count = 0;
	int j = sqrt(n) + 1;
	for(long long int i = 1; i < j; i++) {
		if(n%i == 0)
			count+=2;
	}
	return count;
}

int main(int argc, char* argv[]){
	long long int a, b, n;
	cin>>a>>b>>n;
	int count = 0;
	for(long long int i = a; i<=b; i++){
		if(n == noOfFactors(i))
			count++;
	}
	cout<<count<<"\n";
	return 0;
}