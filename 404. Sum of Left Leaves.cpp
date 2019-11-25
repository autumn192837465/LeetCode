/*
	Find the sum of all left leaves in a given binary tree.

	Example:

		3
	   / \
	  9  20
		/  \
	   15   7

	There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)   return 0;
        int sum = 0;
        Traversals(root,sum,false);
        return sum;
    }
    void Traversals(TreeNode* node,int &sum,bool isLeft){
        if(!node->left && !node->right){
            if(isLeft)
                sum+=node->val;
        }
        else{
            if(node->left)
                Traversals(node->left,sum,true);
            if(node->right)
                Traversals(node->right,sum,false);
        }
    }
};