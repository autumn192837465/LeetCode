/*
	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

	An input string is valid if:

	Open brackets must be closed by the same type of brackets.
	Open brackets must be closed in the correct order.
	Note that an empty string is also considered valid.

	Example 1:

	Input: "()"
	Output: true
	Example 2:

	Input: "()[]{}"
	Output: true
	Example 3:

	Input: "(]"
	Output: false
	Example 4:

	Input: "([)]"
	Output: false
	Example 5:

	Input: "{[]}"
	Output: true
*/
int BracketsToInt(char bracket){
    switch(bracket){
        case '(':
            return 1;
            break;
        case '{':
            return 2;
            break;
        case '[':
            return 3;
            break;
        case ')':
            return 4;
            break;
        case '}':
            return 5;
            break;
        case ']':
            return 6;
            break;
        default :
            return 0;            
    }    
}

class Solution {
public:
    bool isValid(string str) {
        stack<int> s;
        for(int i =0;i<str.size();i++)   {
            int temp = BracketsToInt(str[i]);
            if(s.empty() || temp <= 3){
                s.push(temp);
            }
            else{                                
                else if( == s.top() + 3) s.pop();
                elsereturn false;

                }
            }
        }
        if(s.empty())            
            return true;
        else
            return false;
    }
};