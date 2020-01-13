/*
	Write a function that takes a string as input and reverse only the vowels of a string.

	Example 1:

	Input: "hello"
	Output: "holle"
	Example 2:

	Input: "leetcode"
	Output: "leotcede"
	Note:
	The vowels does not include the letter "y".
*/

class Solution {
public:    
    string reverseVowels(string s) {
        stack<char> vowelStack;        
        vector<int> v;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
             ||s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
              ){
                v.push_back(i);
                vowelStack.push(s[i]);
            }
        }
        for(int i = 0;i<v.size();i++){
            s[v[i]] = vowelStack.top();
            vowelStack.pop();                                                        
        }
        return s;
    }
};