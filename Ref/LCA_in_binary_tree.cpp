#include <iostream>

using namespace std;

struct Node {
	int val;
	struct Node * left;
	struct Node * right;
};

Node * LCA_bottom_up(Node * root, int p, int q) {
	if(!root) {
		return NULL;
	}
	if(root->val == p || root->val == q) {
		return root;
	}
	Node * L = LCA_bottom_up(root->left, p, q);
	Node * R = LCA_bottom_up(root->right, p, q);
	if(L && R) {
		return root;
	}
	return L?L:R;
}

