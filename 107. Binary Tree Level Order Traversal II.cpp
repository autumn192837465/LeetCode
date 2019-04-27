/*
	Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

	For example:
	Given binary tree [3,9,20,null,null,15,7],
		3
	   / \
	  9  20
		/  \
	   15   7
	return its bottom-up level order traversal as:
	[
	  [15,7],
	  [9,20],
	  [3]
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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        Traversal(ans,root,1);
        return ans;
    }
    void Traversal(vector<vector<int>> &ans,TreeNode* node,int level){
        if(!node){
            return;
        }
        
        if(level > ans.size()){
            ans.insert(ans.begin(),vector<int>{node->val});
        }
        else{
            ans[ans.size() - level].push_back(node->val);
        }
        Traversal(ans,node->left,level+1);
        Traversal(ans,node->right,level+1);
    }
};