#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		for(int i = 0; i < n; i++)
			nums[i] += 1;
		for(int i = 0; i < n; i++) {
			if((fabs(nums[i]) - 1) < n) {
				nums[fabs(nums[i])-1] *= -1;
			}
		}
		for(int i = 0; i < n; i++) {
			if(nums[i] > 0)
				return i;
		}
		return n;
	}
};

int main(int argc, char* argv[]) {
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(0);
	// vec.push_back(3);
	Solution s;
	cout<<s.missingNumber(vec)<<endl;
	return 0;
}