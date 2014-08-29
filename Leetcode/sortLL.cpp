/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;


struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        
        if(head == NULL || head->next==NULL)
        	return head;
        
        ListNode *left, *right, *temp, *temp1; 
        
        temp = right = left = head;
        
        while(temp!=NULL && temp->next!=NULL){
        	temp1 = right;
            right = right->next;
        	temp = temp->next->next;
        }
        
        //temp = right;
        //right right->next;
        temp1->next = NULL;
        left =  sortList(left);
        right = sortList(right);
        
        ListNode *ret, *newNode;
        
        if(left!=NULL && right!=NULL) {
            if(left->val > right->val) {
                ret = newNode = right;
                right = right->next;
            }
            else {
                ret = newNode = left;
                left = left->next;
            }
        } else if(left == NULL) {
            return right;
        } else if(right == NULL) {
            return left;
        } else
            return NULL;

        while(left!=NULL && right!=NULL){
        	if(left->val > right->val){
        		newNode->next=right;
        		right = right->next;
        		newNode = newNode->next;
        	} else {
        		newNode->next=left;
        		left = left->next;
        		newNode = newNode->next;
        	}
        }
        
        if(left == NULL)
        	newNode->next = right;
        else
        	newNode->next = left;
        return ret;
    }
};

int main(int argc, char* argv[]){
    Solution s;
    ListNode l1(2);
    ListNode l2(1);
    l1.next = &l2;
    ListNode *l = s.sortList(&l1);
    while(l!=NULL){
        cout<<l->val<<" ";
        l = l->next;
    }
    return 0;
}