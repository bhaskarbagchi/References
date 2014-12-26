#include <iostream>

using namespace std;

struct LL {
	int val;
	struct LL * next;
};

LL * reverseIterative(LL * head) {
	if(head == NULL|| head->next == NULL) {
		return head;
	}
	LL * prev = head;
	head = head->next;
	prev->next = NULL;
	LL * temp;
	while(head != NULL) {
		temp = head->next;
		head->next = prev;
		prev = head;
		head = temp;
	}
	return prev;
}

LL* reverseRecursive(LL* head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}
	LL * partReversed = reverseRecursive(head->next);
	LL * temp = partReversed;
	while(partReversed->next != NULL)
		partReversed = partReversed->next;
	partReversed->next = head;
	head->next = NULL;
	return temp;
}

void printLL(LL * head) {
	while(head) {
		cout<<head->val<<"  ";
		head = head->next;
	}
	cout<<endl;
}

int main(int argc, char* argv[]) {
	LL * head = new LL();
	head->val = 0;
	LL * first = new LL();
	first->val = 1;
	head->next = first;
	LL * second = new LL();
	second->val = 2;
	first->next = second;
	LL * third = new LL();
	third->val = 3;
	second->next = third;
	LL * fourth = new LL();
	fourth->val = 4;
	fourth->next = NULL;
	third->next = fourth;
	printLL(head);
	LL * reverse = reverseRecursive(head);
	printLL(reverse);
	reverse = reverseIterative(fourth);
	printLL(reverse);
	return 0;
}