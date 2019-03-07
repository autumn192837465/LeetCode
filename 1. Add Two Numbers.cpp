/*
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example:

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans = new ListNode(0);
        ListNode *cur = ans;

        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            cur -> next = new ListNode(sum%10);
            cur = cur->next;
            if(l1->next == NULL && l2->next == NULL){
                if(carry == 1){
                    cur->next = new ListNode(1);
                }
                break;
            }
            else if(l1->next == NULL){
                while(carry == 1){
                    sum = carry + l2->next->val;
                    carry = sum/10;
                    cur->next = new ListNode(sum%10);
                    cur = cur->next;
                    l2 = l2->next;
                    if(l2 -> next == NULL && carry == 1){
                        cur-> next = new ListNode(1);
                        return ans->next;
                    }
                }
                cur->next = l2->next;
                break;
            }
            else if(l2->next == NULL){
                while(carry == 1){
                    sum = carry + l1->next->val;
                    carry = sum/10;
                    cur->next = new ListNode(sum%10);
                    cur = cur->next;
                    l1 = l1->next;
                    if(l1 -> next == NULL && carry == 1){
                        cur-> next = new ListNode(1);
                        return ans->next;
                    }
                }
                cur->next = l1->next;
                break;
            }
            else{
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        return ans->next;
    }
};
