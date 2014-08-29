#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int a, b;
        string temp;
        stack<int> stk;
        for(int i = 0; i<tokens.size(); i++){
            string token = tokens.at(i);
            if(token.compare("+") == 0){
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();
                stk.push(a+b);
            } else if(token.compare("-") == 0) {
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();
                stk.push(a-b);
            } else if(token.compare("*") == 0) {
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();
                stk.push(a*b);
            } else if(token.compare("/") == 0) {
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();
                stk.push(a/b);
            } else{
               a = atoi(tokens.at(i).c_str()); 
               stk.push(a);;
            }
        }
        return stk.top();
    }
};

int main(){
    vector<string> vec;
    vec.push_back("0");
    vec.push_back("3");
    vec.push_back("-");
    Solution s;
    cout<<s.evalRPN(vec)<<endl;
    return 0;
}