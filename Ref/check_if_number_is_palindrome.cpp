#include <iostream>

using namespace std;

bool isPalindrome(int x) {
	if(x<0) {
		return false;
	}
	if(x/10 == 0){
		return true;
	}
	int div = 10;
	while(x/div>=10) {
		div = div*10;
	}
	cout<<"div = "<<div<<endl;
	while(x!=0) {
		if(x/div != x%10)
			return false;
		x = (x%div)/10;
		div = div/100;
	}
	return true;
}

bool isPalindromeRec(int x, int &y) {
	if(x<0) {
		return false;
	}
	if(x == 0) {
		return true;
	}
	if(isPalindromeRec(x/10, y) && x%10 == y%10) {
		y/=10;
		return true;
	}
	else {
		return false;
	}
}

bool isPalindromeRec(int x) {
	return isPalindromeRec(x, x);
}

int main(int argc, char* argv[]) {
	int x;
	for(int i = 0; i<10; i++) {
		cin>>x;
		if(isPalindrome(x)){
			cout<<x<<" is a palindrome"<<endl;
		}
		else {
			cout<<x<<" is not a palindrome"<<endl;
		}
	}
	return 0;
}
