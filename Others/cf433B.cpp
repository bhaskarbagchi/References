#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
	int n;
	int q;
	int l, r;
	int temp;
	vector<int> A, B;
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>temp;
		A.push_back(temp);
		B.push_back(temp);
	}
	sort(B.begin(), B.end());
	for(int i = 1; i<n; i++){
		A[i] = A[i] + A[i-1];
		B[i] = B[i] + B[i-1];
	}
	cin>>q;
	for(int i = 0; i<q; i++){
		cin>>temp;
		cin>>l>>r;
		if(l!=1){
			if(temp == 1)
				cout<<A[r-1]-A[l-2]<<endl;
			else
				cout<<B[r-1]-B[l-2]<<endl;
		}
		else{
			if(temp == 1)
				cout<<A[r-1]<<endl;
			else
				cout<<B[r-1]<<endl;
		}
	}
	return 0;
}