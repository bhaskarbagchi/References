#include <iostream>
#include <cstring>

using namespace std;

class Solution{
public:
    void reverseWords(string &s) {
        string delim = " ";
		string token = "";
		string out = "";
		s = trim(s);
		while(!s.empty()){
			token = s.substr(0, s.find(delim));
			out = token + " " + out;
			if(s.erase(0, s.find(delim) + delim.length()).compare(token) == 0){
				break;
			}
			s = trim(s);
		}
		out = trim(out);
		s = out.substr(0, out.length()-1);
    }
private:
    string trim(string s){
        int i = 0;
        for(char c : s){
            if(!isspace(c))
                break;
            i++;
        }
        return s.substr(i, s.length());
    }
};

int main(int argc, char* argv[]){
	Solution sol;
	string s = "sky is blue";
	sol.reverseWords(s);
	cout<<"Reverse : -"<<s<<"-"<<endl;
	return 0;
}