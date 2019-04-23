/*
	Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

	Example 1:

	Input: 1->2->3->3->4->4->5
	Output: 1->2->5
	Example 2:

	Input: 1->1->1->2->3
	Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)   return head;
        ListNode *ans = new ListNode(0);
        ListNode *last = ans;

        while(head){
            bool flag = false;
            while(head->next && head->val == head->next->val){
                flag = true;
                head = head->next;
            }
            if(!flag){
                last->next = head;
                last = last->next;
            }
            head = head->next;
        }
        last->next = NULL;

        return ans->next;
    }
};