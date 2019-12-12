/*
	Given a binary tree, return all root-to-leaf paths.

	Note: A leaf is a node with no children.

	Example:

	Input:

	   1
	 /   \
	2     3
	 \
	  5

	Output: ["1->2->5", "1->3"]

	Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        vector<string> ans;
        Traversal(root,path,ans);        
        return ans;
    }
    void Traversal(TreeNode *n,vector<string> &path,vector<string> &ans){
        if(!n)  return;

        path.push_back(to_string(n->val));
        if(!n->left && !n->right){
            string str;
            for(int i = 0;i<path.size()-1;i++){
                str += path[i] + "->";
            }
            str += path[path.size()-1];
            ans.push_back(str);
            path.pop_back();
            return;
        }
        if(n->left){
            Traversal(n->left,path,ans);
        }
        if(n->right){
            Traversal(n->right,path,ans);
        }
        path.pop_back();
    }
};