/*
	Given a linked list, remove the n-th node from the end of list and return its head.

	Example:

	Given linked list: 1->2->3->4->5, and n = 2.

	After removing the second node from the end, the linked list becomes 1->2->3->5.
	Note:

	Given n will always be valid.
*/
int ToNextNode(ListNode* l,int target){
    if(l){
        int idx = ToNextNode(l->next,target);
        if(idx == -1)   return -1;
        if(idx == target){
            l->next = l->next->next;
            return -1;
        }
        return idx + 1;
    }
    return 0;
}
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *dummy = new ListNode(0);
        dummy ->next = head;
        ToNextNode(dummy,n);
        return dummy->next;
    }
};