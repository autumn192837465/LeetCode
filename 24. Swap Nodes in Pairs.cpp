/*
	Given a linked list, swap every two adjacent nodes and return its head.

	You may not modify the values in the list's nodes, only nodes itself may be changed.

	 

	Example:

	Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur;
        ListNode *nextNode;
        ListNode *lastNode = NULL;

        if(head && head->next){
            cur = head;
            if(head->next->next){
                nextNode = head->next->next;
            }
            head = head->next;
            lastNode = cur;
            head->next = cur;
            cur = nextNode;
        }
        else{
            return head;
        }

        while(cur && cur->next){

            if(cur->next->next){
                nextNode = cur->next->next;
            }
            else{
                nextNode = NULL;
            }
            lastNode->next = cur->next;
            lastNode->next->next = cur;
            lastNode = cur;
            cur = nextNode;
        }

        lastNode->next = cur;    
        return head;
    }
};