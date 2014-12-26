#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
};

Node * LCA(Node* root, Node* p, Node* q) {
	if(!root || !p || !q) {
		return NULL;
	}
	Node * left;
	Node * right;
	if(p->val > q->val) {
		left = q;
		right = p;
	}
	else if(q->val > p->val) {
		left = p;
		right = q;
	}
	else {
		return NULL;
	}
	if(left->val < root->val && right->val < root->val) {
		return LCA(root->left, p, q);
	} else if(left->val > root->val && right->val > root->val) {
		return LCA(root->right, p, q);
	} else {
		return root;
	}
}

Node * LCA(Node* root, int p, int q) {
	if(!rootw) {
		return NULL;
	}
	int left;
	int right;
	if(p > q) {
		left = q;
		right = p;
	}
	else if(q > p) {
		left = p;
		right = q;
	}
	else {
		return NULL;
	}
	if(left->val < root->val && right->val < root->val) {
		return LCA(root->left, p, q);
	} else if(left->val > root->val && right->val > root->val) {
		return LCA(root->right, p, q);
	} else {
		return root;
	}
}
/*
void insterIntoBST(Node* root, int val) {
	Node* new_node = new Node();
	new_node->val = val;
	new_node->left = NULL;
	new_node->right = NULL;
	if(root == NULL) {
		return new_node;
	}
	while(root!= NULL) {
		if(root->val === val)
			return;

	}
}

void createBST() {
	for()
}
*/
int main(int argc, char* argv[]) {

}