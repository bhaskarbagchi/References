#include <iostream>

using namespace std;

bool is_BTS_post_order(int sequence[], int length) {
	if(sequence == NULL || length<=0) {
		return false;
	}
	int root = sequence[length-1];
	int i = 0;
	for(; i < length-1; i++) {
		if(sequence[i] > root)
			break;
	}
	int j = i;
	for(; j<length-1; j++) {
		if(sequence[j]<root) 
			return false;
	}

	bool left = true;
	if(i > 0)
		left = is_BTS_post_order(sequence, i);

	bool right = true;
	if(i < length-1)
		right = is_BTS_post_order(sequence+i, length-1 - i);

	return left && right;
}

int main(int argc, char* argv[]) {
	int A[] = {5, 7, 6, 9, 11, 10, 8};
	int len = 7;
	if(is_BTS_post_order(A, len)) {
		cout<<"It is post order traversal sequence of a BST"<<endl;
	}
	else {
		cout<<"It is NOT a post order traversal sequence of a BST"<<endl;
	}
	return 0;
}