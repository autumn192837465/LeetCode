/*
	Reverse a linked list from position m to n. Do it in one-pass.

	Note: 1 ≤ m ≤ n ≤ length of list.

	Example:

	Input: 1->2->3->4->5->NULL, m = 2, n = 4
	Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)  return head;
        ListNode *pre = new ListNode(0);
        pre->next = head;

        ListNode *p = pre;
        while(m-- > 1){
            p = p->next;
            n--;
        }
        head = p;
        p = p->next;
        ListNode *tail = p;

        ListNode *q = p->next;
        ListNode *r;
        for(int i = 1;i<n;i++){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        head->next = p;
        tail->next = r;
        p = pre->next;

        return pre->next;
    }
};
