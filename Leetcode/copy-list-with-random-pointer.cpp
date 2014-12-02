#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode *temp, *newHead, *iterating;
        iterating = head;
        while(iterating!= NULL){
            temp = (RandomListNode *)malloc(sizeof(RandomListNode));
            temp->label = iterating->label;
            temp->next = iterating->next;
            temp->random = NULL;
            iterating->next = temp;
            iterating = temp->next;
        }
        newHead = head->next;
        iterating = head;
        while(iterating->next->next != NULL){
            iterating->next->random = iterating->random->next;
            iterating = iterating->next->next;
        }
        iterating = head;
        while(iterating->next != NULL){
            temp = iterating->next;
            iterating->next = temp->next;
            iterating = temp;
        }
        return newHead;
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