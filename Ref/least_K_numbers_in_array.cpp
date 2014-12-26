//multiset is implemented as red-black tree so insert, find etc operations are performed in log(n) time

#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> leastK(vector<int> numbers, int k) {
	vector<int> ret;
	if(k < 1 || numbers.size() == 0 || numbers.size() < k) {
		return ret;
	}
	multiset<int, greater<int> > least;
	vector<int>::iterator iter = numbers.begin();
	for(; iter != numbers.end(); iter++) {
		if(least.size() < k) {
			least.insert(*iter);
		} else {
			multiset<int, greater<int> >::iterator greater = least.begin();
			if(*iter < *greater) {
				least.erase(greater);
				least.insert(*iter);
			}
		}
	}
	multiset<int, greater<int> >::iterator it = least.begin();
	for(; it != least.end(); it++) {
		ret.push_back(*it);
	}
	return ret;
}

int main(int arcg, char* argv[]) {
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
	vector<int> got = leastK(A, 3);
	if(got.size() > 0) {
		for(int i = 0; i< got.size(); i++) {
			cout<<got[i]<<"  ";
		}
	}
	else {
		cout<<"Got empty";
	}
	cout<<endl;
}