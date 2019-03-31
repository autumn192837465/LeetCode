/*
	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

	For example:
	Given binary tree [3,9,20,null,null,15,7],
		3
	   / \
	  9  20
		/  \
	   15   7
	return its level order traversal as:
	[
	  [3],
	  [9,20],
	  [15,7]
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

void Traversal(vector<vector<int>> &ans,TreeNode* node,int level){

    if(ans.size() <= level){
        ans.push_back(vector<int>{node->val});
    }
    else{
        ans[level].push_back(node->val);
    }
    if(node->left)
        Traversal(ans,node->left,level+1);
    if(node->right)
        Traversal(ans,node->right,level+1);
}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        Traversal(ans,root,0);
        return ans;
    }
};