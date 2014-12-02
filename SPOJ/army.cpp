#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	int NG=0, NM=0, gMax=0, mMax=0, temp;
	while(t){
		--t;
		cin>>NG>>NM;
		while(NG){
			--NG;
			cin>>temp;
			if(temp>gMax)
				(gMax=temp);
		}
		while(NM){
			--NM;
			cin>>temp;
			if(temp>mMax)
				(mMax=temp);
		}
		if(gMax>=mMax)
			cout<<"Godzilla\n";
		else
			cout<<"MechaGodzilla\n";
	}
	return 0;
}