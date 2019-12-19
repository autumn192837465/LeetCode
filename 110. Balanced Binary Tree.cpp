/*
	Given a binary tree, determine if it is height-balanced.

	For this problem, a height-balanced binary tree is defined as:

	a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

	 

	Example 1:

	Given the following tree [3,9,20,null,null,15,7]:

		3
	   / \
	  9  20
		/  \
	   15   7
	Return true.

	Example 2:

	Given the following tree [1,2,2,3,3,null,null,4,4]:

		   1
		  / \
		 2   2
		/ \
	   3   3
	  / \
	 4   4
	Return false.
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return FindHight(root) != -1;
    }

    int FindHight(TreeNode* node){
        if(!node)   return 0;
        int left = FindHight(node->left);
        int right = FindHight(node->right);
        if(left == -1 || right == -1 || abs(left-right) > 1){
            return -1;
        }
        return max(left,right) + 1;
    }
};