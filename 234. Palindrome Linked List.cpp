/*
	Given a singly linked list, determine if it is a palindrome.

	Example 1:

	Input: 1->2
	Output: false
	Example 2:

	Input: 1->2->2->1
	Output: true
	Follow up:
	Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        int len = 0;
        while(cur){
            len++;
            cur = cur->next;
        }
        stack<int> s;
        cur = head;
        int i = 0;
        for(;i<len/2;i++){
                s.push(cur->val);
                cur = cur->next;
        }
        if(len%2 == 1)   {
            cur = cur->next;
            i++;
        }
        
        for(;i<len;i++){
                if(s.top() != cur->val) return false;
                s.pop();
                cur = cur->next;
        }
        
            
       
        return true;
    }
};
