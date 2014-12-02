struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
         
    }

    ListNode *mergeLists(ListNode* first, ListNode* second){
    	ListNode* temp1 = first;
    	ListNode* temp2 = second;
    	ListNode* ret, temp;
    	if(temp1->val < temp2->val){
    		temp = ret = temp1;
    		temp1 = temp1->next;
    	}
    	else {
    		temp = ret = temp2;
    		temp2 = temp2->next;
    	}
    	while(temp1 != NULL || temp2 != NULL) {
    		if(temp1->val < temp2->val){
    			temp->next = temp1;
    			temp1 = temp1->next;
    		}
    		else {
    			temp->next = temp2;
    			temp2 = temp2->next;;
    		}
    	}
    	if(temp1 == NULL){
    		temp->next = temp2;
    	}
    	else {
    		temp->next = temp1;
    	}
    	return ret;
    }
};