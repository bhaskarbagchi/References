#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class inorderTraversal {
public:
	vector<int> iterative(TreeNode* root) {

	}

	vector<int> recursive(TreeNode* root) {
		vector<int> a, b;
		if(root == NULL)
			return a;
		a = recursive(root->left);
		a.push_back(root->val);
		b = recursive(root->right);
		if(b.size() >0)
			a.insert(a.end(), b.begin(), b.end());
		return a;
	}
};

int main(int argc, char* argv[]) {
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	inorderTraversal inorder;
	vector<int> output1 = inorder.recursive(&n1);
	for(vector<int>::iterator it = output1.begin(); it<=output1.end(); it++){
		cout<<*it<<" ";
	}
	cout<<"\n";
	return 0;
}