/*
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

	For example, given n = 3, a solution set is:

	[
	  "((()))",
	  "(()())",
	  "(())()",
	  "()(())",
	  "()()()"
	]
*/
void AddParenthesis(int count,int left,int right,vector<string>&ans,string s){
    if(count == 0){
        ans.push_back(s);
        return;
    }
    if(left > 0 && left<=right){
        AddParenthesis(count-1,left-1,right,ans,s+"(");
    }
    if(right >left){
        AddParenthesis(count-1,left,right-1,ans,s+")");
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        AddParenthesis(2*n,n,n,ans,"");
        return ans;
    }
};