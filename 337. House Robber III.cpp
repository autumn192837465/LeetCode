/*
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Money{
    int notRobbed;
    int robbed;
    Money(int x,int y) : notRobbed(x), robbed(y) {};
};
class Solution {
public:
    int rob(TreeNode* root) {

        Money m = Robbing(root);
        return max(m.notRobbed,m.robbed);
    }
    Money Robbing(TreeNode* node){
        if(!node){
            Money m(0,0);
            return m;
        }
        if(!node->left && !node->right){
            Money m(0,node->val);
            return m;
        }

        Money left = Robbing(node->left);
        Money right = Robbing(node->right);
        Money m(max(left.robbed,left.notRobbed) + max(right.robbed,right.notRobbed),left.notRobbed + right.notRobbed + node->val);

        return m;
    }
};