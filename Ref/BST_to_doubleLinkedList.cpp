#include <iostream>

using namespace std;

struct Node {
	int val; 
	struct Node * left;
	struct Node * right;
};

Node* BST_to_DLL(Node* root) {
	if(root == NULL) {
		return root;
	}
	Node * last = BST_to_DLL(root->left);
	Node * thisNode = new Node();
	thisNode->val = root->val;
	thisNode->left = last;
	if(last!=NULL)
		last->right = thisNode;
	Node* next = BST_to_DLL(root->right);
	if(next!=NULL) {
		Node * ret = next;
		while(next->left != NULL)
			next = next->left;
		next->left = thisNode;
		thisNode->right = next;
		return ret;
	}
	return thisNode;
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
	Node * last = BST_to_DLL(five);
	Node * prev;
	while(last != NULL) {
		cout<<last->val<<"  ";
		prev = last;
		last = last->left;
	}
	cout<<endl;
	while(prev!=NULL) {
		cout<<prev->val<<"  ";
		prev = prev->right;
	}
	cout<<endl;
	return 0;
}