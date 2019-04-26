/*
	Given a singly linked list L: L0→L1→…→Ln-1→Ln,
	reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

	You may not modify the values in the list's nodes, only nodes itself may be changed.

	Example 1:

	Given 1->2->3->4, reorder it to 1->4->2->3.
	Example 2:

	Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)   return;
        ListNode *p1 = head,*p2 = head->next;

        //Find middle node
        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }    
        //Reverse the second half
        p2 = p1->next;
        p1->next = NULL;

        p1 = p2;
        ListNode *p3 = p2->next;
        p1->next = NULL;
        while(p3){
            p2 = p3;
            p3 = p3->next;
            p2->next = p1;
            p1 = p2;
        }

        p1 = head;
        while(p1 && p2){
            p3 = p1->next;
            p1->next = p2;
            p1 = p3;

            p3 = p2->next;
            p2->next = p1;
            p2 = p3;
        }
    }
};
