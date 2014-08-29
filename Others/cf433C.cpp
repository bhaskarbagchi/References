#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
	int n, m, temp;
	cin>>n>>m;
	vector<int> v, v1;
	for(int i = 0; i<n; i++){
		cin>>temp;
		v.push_back(temp);
	}
	for(int i = 0; i < n-2; i++){
		v1.push_back(fabs(v[i]-v[i+1]) + fabs(v[i+1]-v[i+2]) - fabs(v[i]-v[i+2]));
	}
	int N=n-2;
	int index = distance(v1.begin(), max_element(v1.begin(), v1.end()));
	cout<<index<<endl;
	return 0;
}