//Also works for general binary tree. Not necessarily a BST
#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int val;
	struct Node * left;
	struct Node * right;
};

bool findPath(Node * root, int expectedSum, vector<int> path) {
	if(root->left == NULL && root->right == NULL && expectedSum == root->val) {
		cout<<"Path found :"<<endl;
		for(int i = 0; i<path.size(); i++)
			cout<<path[i]<<"  ";
		cout<<root->val<<endl;
		return true;
	}
	path.push_back(root->val);
	bool left = false, right = false;
	if(root->left != NULL)
		left = findPath(root->left, expectedSum - root->val, path);
	if(root->right!=NULL)
		right = findPath(root->right, expectedSum - root->val, path);
	path.pop_back();
	return left || right;
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
	vector<int> path;
	if(findPath(five, 11, path) == false)
		cout<<"No path found"<<endl;
	return 0;
}