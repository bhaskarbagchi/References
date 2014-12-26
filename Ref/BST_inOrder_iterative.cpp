#include <stack>
#include <iostream>

using namespace std;

struct BST_Node {
	int val;
	struct BST_Node * left;
	struct BST_Node * right;
};

void inOrderTraversal(BST_Node * root) {
	stack<BST_Node *> q;
	BST_Node * current = root;
	BST_Node * temp;
	while(current || !q.empty()) {
		if(current != NULL) {
			q.push(current);
			current = current->left;
		} else {
			temp = q.top();
			current = temp->right;
			cout<<temp->val<<"  ";
			q.pop();
		}
	}
}

int main(int argc, char* argv[]) {
	BST_Node * five = new BST_Node();
	five->val = 5;
	BST_Node * two = new BST_Node();
	two->val = 2;
	BST_Node * four = new BST_Node();
	four->val = 4;
	BST_Node * eight = new BST_Node();
	eight->val = 8;
	BST_Node * fifteen = new BST_Node();
	fifteen->val = 15;
	BST_Node * one = new BST_Node();
	one->val = 1;
	BST_Node * three = new BST_Node();
	three->val = 3;
	BST_Node * six = new BST_Node();
	six->val = 6;
	BST_Node * nine = new BST_Node();
	nine->val = 9;
	BST_Node * sixteen = new BST_Node();
	sixteen->val = 16;
	BST_Node * seven = new BST_Node();
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
	inOrderTraversal(five);
	return 0;
}
/*
					5
		3						9
	2		4				8		15
1 						6				16
							7
*/