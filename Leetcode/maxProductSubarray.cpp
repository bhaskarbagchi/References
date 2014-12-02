#include <iostream>

using namespace std;

class Solution {
public:
    int maxProductFn(int A[], int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return A[0];
        int begin = 0, end = 0, currProduct = A[0], maxProduct = A[0], tempBegin = 0, tempEnd = 0;
        for(int i = 1; i<n; i++) {
            //currProduct *= A[i];
            if(currProduct * A[i] >= maxProduct) {
                maxProduct = currProduct*A[i];
                begin = tempBegin;
                end = tempEnd;
            } else if(A[i] > maxProduct) {
                maxProduct = currProduct = A[i];
                begin = tempBegin = i;
                end = tempEnd = i;
            } else if (currProduct * A[i] >=currProduct) {
                currProduct *= A[i];
                tempEnd = i;
            } else {
                currProduct = A[i];
                tempBegin = i;
                tempEnd = i;
            }
            cout<<i<<" "<<currProduct<<" "<<maxProduct<<" "<<begin<<" "<<end<<" "<<tempBegin<<" "<<tempEnd<<endl;
        }
        return maxProduct;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    int A[] = {-7, -6, -5, -4, -8};
    cout<<s.maxProductFn(A, 5)<<endl;
    return 0;
}