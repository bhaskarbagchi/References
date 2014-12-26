#include <iostream>
#include <cstring>

using namespace std;

char firstCharAppearingOnce(char str[]) {
	int A[26];
	for(int i = 0; i < 26; i++) {
		A[i] = -2;
	}
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(A[str[i] - 'a'] == -2) {
			A[str[i] - 'a'] = i;
		}
		else {
			A[str[i] - 'a'] = -1;
		}
	}
	int min = 27;
	for(int i =0; i < 26; i++) {
		if(A[i] >= 0 && A[i] < min)
			min = i;
	}
	if(0 <= min && min <= 25)
		return min+'a';
	return -1;
}

int main(int argc, char* argv[]) {
	char str[] = "abaccdeffbde";
	char c = firstCharAppearingOnce(str);
	if(c != 'a' - 1) {
		cout<<c<<endl;
	}
	else {
		cout<<"Not found"<<endl;
	}
	return 0;
}