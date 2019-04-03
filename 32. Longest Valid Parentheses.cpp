/*
	Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

	Example 1:

	Input: "(()"
	Output: 2
	Explanation: The longest valid parentheses substring is "()"
	Example 2:

	Input: ")()())"
	Output: 4
	Explanation: The longest valid parentheses substring is "()()"	
*/
class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        s.push(-1);
        int ans = 0;
        for(int i = 0;i<str.size();i++){
            if(str[i] == '('){
                s.push(i);
            }
            else{
                s.pop();
                if(s.empty()){
                   s.push(i) ;
                }
                else{
                    ans = max(ans,i - s.top());
                }
            }
        }
        return ans;
    }
};