#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<vector<int> > findTuples(vector<int> array, int k) {
	sort(array.begin(), array.end());
	set<vector<int> > tuples;
	vector<int> tuple(3);
	int p, q;
	int size = array.size();
	for(int i = 0; i <= size - 2; i++) {
		p = i+1;
		q = size-1;
		while(p<q) {
			if(array[i] + array[p] + array[q] < k) {
				p++;
			}
			else if(array[i] + array[p] + array[q] > k) {
				q--;
			}
			else {
				tuple[0] = array[i];
				tuple[1] = array[p];
				tuple[2] = array[q];
				p++;
				q--;
			}
		}
	}
	return tuples;
}

void printTuples(set<vector<int> > tuples) {
	/*
	 * TODO
	 */
}

int main(int argc, char* argv[]) {
	vector<int> array;
	array.push_back(-1);
	array.push_back(0);
	array.push_back(1);
	array.push_back(2);
	array.push_back(-1);
	array.push_back(-4);
	set<vector<int> > tuples = findTuples(array, 0);
	printTuples(tuples);
	return 0;
}