#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int hIndex(std::vector<int>& citations) {
		std::sort(citations.begin(), citations.end(), std::greater<int>());
		int size = citations.size();
		int h_index = 0;
		for(int i = 0; i < size; i++) {
			if(citations[i] >= (i+1))
				h_index = (i+1);
		}
		return h_index;
	}
};

int main(int argc, char* argv[]) {
	std::vector<int> vec;
	vec.push_back(3);
	vec.push_back(0);
	vec.push_back(6);
	vec.push_back(1);
	vec.push_back(5);
	Solution s;
	std::cout<<s.hIndex(vec)<<std::endl;
	return 0;
}