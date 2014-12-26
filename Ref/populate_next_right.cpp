#include <iostream>

using namespace std;

struct Node {
	int val;
	struct Node * left;
	struct Node * right;
	struct Node * next_right;
};

void connect(Node * root) {
	if(!root) {
		return;
	}
	if(!root->left || !root->right) {
		return;
	}
	Node * p1 = root;
	Node * rightSibbling;
	while(p1) {
		if(!p1->next_right) {
			p1->left->next_right = p1->right;
			p1->right->next_right = NULL;
		} else {
			rightSibbling = p1->next_right->left;
			p1->left->next_right = p1->right;
			p1->right->next_right = rightSibbling;
		}
		p1 = p1->next_right;
	}
	connect(root->left);
}

void connect_using_BFS(Node * root) {
	if(!root) {
		return;
	}
	if(!root->left || ! root->right) {
		return;
	}
	root->left->next_right = root->right;
	if(root->next_right) {
		root->right->next_right = root->next_right->left;
	} else {
		root->right->next_right = NULL;
	}
	connect_using_BFS(root->left);
	connect_using_BFS(root->right);
}