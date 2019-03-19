/*
	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

	Example:

	Input:
	[
	  1->4->5,
	  1->3->4,
	  2->6
	]
	Output: 1->1->2->3->4->4->5->6
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        ListNode *p;
        for(vector<ListNode*>::iterator it = lists.begin();it!=lists.end();it++){
            p = *it;
            while(p){                
                arr.push_back(p->val);
                p = p->next;
            }
        }

        sort(arr.begin(),arr.end());
        ListNode *ans = new ListNode(0);
        p = ans;
        for(vector<int>::iterator it = arr.begin();it!=arr.end();it++){
            p->next = new ListNode(*it);
            p = p->next;
        }        
        return ans->next;
    }
};