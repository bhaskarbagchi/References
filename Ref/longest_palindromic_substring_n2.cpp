#include <iostream>

using namespace std;

//Using n2 space and n2 time
string longestPalindromicSubstring(string str) {
	int len = str.length();
	int longestBegin = 0;
	int longestLength = 1;
	bool isPalindrom[1000][1000]={false};
	
	for(int i = 0; i<len; i++) {
		isPalindrom[i][i] = true;
	}
	
	for (int i = 0; i < len - 1; i++) {
		if(str[i] == str[i+1]) {
			isPalindrom[i][i+1] = true;
			longestBegin = i;
			longestLength = 2;
		}
	}
	for(int i = 3; i<len; i++) {
		for(int j = 0; j<len-i+1; j++) {
			int k = j+i-1;
			if(str[j] == str[k] && isPalindrom[j+1][k-1]) {
				isPalindrom[i][j] = true;
				longestLength = i;
				longestBegin = j;
			}
		}
	}
	for(int i = 0; i<len; i++) {
		for(int j = 0; j<len; j++) {
			cout<<isPalindrom[i][j]<<"\t";
		}
		cout<<endl;
	}
	return str.substr(longestBegin, longestLength);
}


//Using n2 time and o(0) space

string expandAroundCentre(string str, int c1, int c2) {
	int l = c1, r = c2;
	int n = str.length();
	while(l>0 && r<n && str[l] == str[r]) {
		l--; r++;
	}
	return str.substr(l+1, r-l-1);
}

string longestPalindromicSubstringNoSpace(string str) {
	if(str.length() == 0 || str.length() == 1) {
		return str;
	}
	int n = str.length();
	string palondrom = str.substr(0, 1);
	for(int i = 0; i < n-1; i++) {
		string p1 = expandAroundCentre(str, i, i);
		if(p1.length() > palondrom.length()) {
			palondrom = p1;
		}
		string p2 = expandAroundCentre(str, i, i+1);
		if(p2.length() > palondrom.length()) {
			palondrom = p2;
		}
	}
	return palondrom;
}

int main(int argc, char* argv[]) {
	string str;
	cout<<"enter string: ";
	cin>>str;
	cout<<"The longest palindromic substring is : "<<longestPalindromicSubstring(str)<<endl;
	cout<<"The longest palindromic substring is : "<<longestPalindromicSubstringNoSpace(str)<<endl;
	return 0;
}