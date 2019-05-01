/*
	Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

	Note: A leaf is a node with no children.

	Example:

	Given the below binary tree and sum = 22,

		  5
		 / \
		4   8
	   /   / \
	  11  13  4
	 /  \    / \
	7    2  5   1
	Return:

	[
	   [5,4,11,2],
	   [5,8,4,5]
	]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> v;

        stack<TreeNode*> s;
        TreeNode *pre;

        while(root || !s.empty()){
            while(root){
                s.push(root);
                v.push_back(root->val);
                sum -= root->val;
                root = root->left;
            }
            root = s.top();

            if(!root->left && !root->right && root->right != pre && !sum){
                pre = root;
                ans.push_back(v);
                s.pop();
                sum+=root->val;
                v.pop_back();
                root = NULL;
                continue;

            }
            if(root->right && root->right != pre){
                root = root->right;
            }
            else{
                pre = root;
                s.pop();
                v.pop_back();
                sum+=root->val;
                root = NULL;
            }
        }
        return ans;
    }
};

// Solution 2 Recursive
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> v;

        stack<TreeNode*> s;
        TreeNode *pre;

        while(root || !s.empty()){
            while(root){
                s.push(root);
                v.push_back(root->val);
                sum -= root->val;
                root = root->left;
            }
            root = s.top();

            if(!root->left && !root->right && root->right != pre && !sum){
                pre = root;
                ans.push_back(v);
                s.pop();
                sum+=root->val;
                v.pop_back();
                root = NULL;
                continue;

            }
            if(root->right && root->right != pre){
                root = root->right;
            }
            else{
                pre = root;
                s.pop();
                v.pop_back();
                sum+=root->val;
                root = NULL;
            }

        }
        return ans;
    }
};