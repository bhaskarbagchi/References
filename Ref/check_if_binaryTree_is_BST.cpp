#include <iostream>
#include <climits>

using namespace std;

struct Node {
	int val;
	struct Node * left;
	struct Node * right;
};

bool isBST(Node * root, int min, int max) {
	if(!root)
		return true;
	if(min < root->val && root->val < max)
		return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
	return false;
}

int main(int argc, char* argv[]) {
	Node * five = new Node();
	five->val = 5;
	Node * two = new Node();
	two->val = 2;
	Node * four = new Node();
	four->val = 4;
	Node * eight = new Node();
	eight->val = 8;
	Node * fifteen = new Node();
	fifteen->val = 15;
	Node * one = new Node();
	one->val = 1;
	Node * three = new Node();
	three->val = 3;
	Node * six = new Node();
	six->val = 6;
	Node * nine = new Node();
	nine->val = 9;
	Node * sixteen = new Node();
	sixteen->val = 16;
	Node * seven = new Node();
	seven->val = 7;
	five->left = three;
	five->right = nine;
	three->left = two;
	three->right = four;
	nine->left = eight;
	nine->right = fifteen;
	two->left = one;
	eight->left = six;
	six->right = seven;
	fifteen->right = sixteen;
	if(isBST(five, INT_MIN, INT_MAX))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}