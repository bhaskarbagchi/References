#include <iostream>

using namespace std;

struct LinkedList {
	int val;
	struct LinkedList * next;
};

LinkedList * insert(int data, LinkedList* head) {
	LinkedList* new_node = new LinkedList();
	new_node->val = data;
	new_node->next = NULL;
	if(head == NULL) {
		new_node->next = new_node;
		return new_node;
	}
	if(head->next == head) {
		head->next = new_node;
		new_node->next = head;
		return head;
	}
	while(1) {
		head = head->next;
		if(data <head->next->val && head->val <= data){
			LinkedList* temp = head->next;
			head->next = new_node;
			new_node->next = temp;
			return head;
		}
		if(head->next->val < head->val && head->val <= data) {
			LinkedList* temp = head->next;
			head->next = new_node;
			new_node->next = temp;
			return head;
		}
		if(head->next->val < head->val && data <= head->next->val) {
			LinkedList* temp = head->next;
			head->next = new_node;
			new_node->next = temp;
			return head;
		}
	}
}

void printLL(LinkedList* head) {
	if(head == NULL) {
		cout<<"NULL"<<endl;
		return;
	}
	LinkedList* temp = head;
	do {
		cout<<temp->val<<"\t";
		temp = temp->next;
	} while(head != temp);
	cout<<endl;
}

int main(int argc, char* argv[]) {
	int val = 0;
	LinkedList* head = NULL;
	while(val != -1) {
		printLL(head);
		cin>>val;
		head = insert(val, head);
	}
	cout<<"Done!"<<endl;
} 