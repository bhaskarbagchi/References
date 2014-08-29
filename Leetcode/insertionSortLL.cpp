#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
        	return head;
        ListNode *ret, *temp, *temp1;
        ret = head;
        head = head->next;
        ret->next = NULL;

        while(head!=NULL) {
        	if(head->val < ret->val) {
        		temp = head;
        		head = head->next;
        		temp->next = ret;
        		ret = temp;
        	} else {
        		temp1 = ret;
        		temp = ret->next;
        		while(temp!=NULL) {
        			if(temp->val>head->val)
        				break;
        			temp1 = temp1->next;
        			temp = temp->next;
        		}
        		temp1->next = head;
        		head = head->next;
        		temp1 = temp1->next;
        		temp1->next = temp;
        	}

        }
        return ret;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
    ListNode l1(3);
    ListNode l2(2);
    ListNode l3(4);
//    ListNode l4(3);
    l1.next = &l2;
    l2.next = &l3;
//    l3.next = &l4;
    ListNode *l = s.insertionSortList(&l1);
    while(l!=NULL){
        cout<<l->val<<" ";
        l = l->next;
    }
    return 0;
}