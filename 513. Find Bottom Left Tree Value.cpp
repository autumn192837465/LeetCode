/*
    Given a binary tree, find the leftmost value in the last row of the tree.

	Example 1:
	Input:

		2
	   / \
	  1   3

	Output:
	1
	Example 2: 
	Input:

			1
		   / \
		  2   3
		 /   / \
		4   5   6
		   /
		  7

	Output:
	7
	Note: You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int layer = -1;
        int ans ;
        q.push(make_pair(root,0));
        while(!q.empty()){
            int l = q.front().second;
            TreeNode *t = q.front().first;

            if(l > layer){
                layer = l;
                ans = t->val;
            }
            if(t->left){
                q.push(make_pair(t->left,l + 1));
            }
            if(t->right){
                q.push(make_pair(t->right,l + 1));
            }
            q.pop();
        }

        return ans;
    }

};