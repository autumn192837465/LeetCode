/*
	Given a binary tree, find its minimum depth.

	The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

	Note: A leaf is a node with no children.

	Example:

	Given binary tree [3,9,20,null,null,15,7],

		3
	   / \
	  9  20
		/  \
	   15   7
	return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        int ans=INT_MAX;
        FindMinDepth(root,0,ans);
        
        return ans+1;
    }
    void FindMinDepth(TreeNode* root,int depth,int &ans){
        if(depth >= ans){
            return;
        }
        if(!root->left && !root->right){
            ans = depth;
            return;
        }
        if(root->left)
            FindMinDepth(root->left,depth+1,ans);
        if(root->right)
            FindMinDepth(root->right,depth+1,ans);
        return;
    }
};