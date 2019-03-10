/*
	Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

	Example:

	Input: 1->2->4, 1->3->4
	Output: 1->1->2->3->4->4
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1){
            return l2;
        }
        else if(!l2){
            return l1;
        }        
        
        
        ListNode *ans = new ListNode(0);
        ListNode *cur = ans;

        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = new ListNode(l1->val);
                cur = cur->next;
                if(l1->next)
                    l1 = l1->next;
                else{
                    cur->next = l2;
                    break;
                }
            }
            else{
                cur->next = new ListNode(l2->val);
                cur = cur->next;
                if(l2->next)
                    l2 = l2->next;
                else{
                    cur->next = l1;
                    break;
                }
            }
        }        
        //PrintListNode(ans->next);
        return ans->next;
    }
};

