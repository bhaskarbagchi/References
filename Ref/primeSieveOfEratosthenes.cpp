#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> findPrimes(int n) {
	vector<bool> isPrimie(n);
	isPrimie[0] = isPrimie[1] = false;
	isPrimie[2] = true;
	for(int i = 3; i < n; i++) {
		isPrimie[i] = i%2;
	}
	int limit = sqrt(n) + 1;
	for(int i = 2; i < limit; i++) {
		if(isPrimie[i]) {
			for(int j = i * i; j < n; j = j + i) {
				isPrimie[j] = false;
			}
		}
	}
	vector<int> primes;
	for(int i = 0; i < n; i++) {
		if(isPrimie[i])
			primes.push_back(i);
	}
	return primes;
}

int main(int argc, char* argv[]) {
	int n;
	cin>>n;
	vector<int> primes = findPrimes(n);
	int size = primes.size();
	for(int i = 0; i < size; i++) {
		cout<<primes[i]<<endl;
	}
	return 0;
}