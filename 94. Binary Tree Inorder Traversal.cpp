/*
	Given a binary tree, return the inorder traversal of its nodes' values.

	Example:

	Input: [1,null,2,3]
	   1
		\
		 2
		/
	   3

	Output: [1,3,2]
	Follow up: Recursive solution is trivial, could you do it iteratively?

	Accepted
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
 // Solution 1 Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)   return ans;

        stack<TreeNode*> s;

        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            ans.push_back(root->val);
            s.pop();
            root = root->right;
        }

        return ans;
    }
};
// Solution 2 Recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        Tranversal(root,ans);
        return ans;
    }
    
    void Tranversal(TreeNode* node, vector<int> &ans){
        if(!node)   return;
        Tranversal(node->left,ans);
        ans.push_back(node->val);
        Tranversal(node->right,ans);        
        return;
    }
};