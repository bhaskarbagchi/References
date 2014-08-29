#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
	int n, m, i, in, last, first, count = 0, flag = 0;
	cin>>n>>m;
	int* A = (int *)malloc(n*sizeof(int));
	for (i = 0; i < n; ++i){
		A[i] = 0;
	}
	char ch;
	//while(m>0){
	for(i = 0; i<m; i++){
		cin>>ch>>in;
		if(ch == '+'){
			if(i == 0)
				first = in;
            if(last == in-1){
                A[in-1] = 0;
            }
            else{
                A[in-1] = 1;
            }
            last = -1;
        }
        else{
            last = in-1;
            A[in-1] = -1;
            if(i == m-1 && in == first)
            	A[in-1] = 0;
        }
        //m--;
    }
    
    if(A[first - 1] == 1)
    	A[first - 1] = 0;

    for(i = 0; i<n; i++){
        if(A[i] == 0)
            count++;
    }

    cout<<count<<endl;
    for(i = 0; i<n; i++){
        if(A[i] == 0)
            cout<<i+1<<" ";
    }
    cout<<endl;
	return 0;
}