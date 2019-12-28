/*
	You need to find the largest value in each row of a binary tree.

	Example:
	Input: 

			  1
			 / \
			3   2
		   / \   \  
		  5   3   9 

	Output: [1, 3, 9]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        vector<int> ans;
        if(!root)   return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int maxVal = INT_MIN;
            int qlen = q.size();
            for(int i = 0;i<qlen;i++){
                TreeNode *p = q.front();
                maxVal = max(maxVal,p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                q.pop();
            }
            ans.push_back(maxVal);
        }
        for(auto i : ans)
            cout<<i;
        return ans;
    }
};