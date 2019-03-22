/*
	Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

	If the last word does not exist, return 0.

	Note: A word is defined as a character sequence consists of non-space characters only.

	Example:

	Input: "Hello World"
	Output: 5
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int idx = s.size();
        while(s[idx-1] == ' ' && idx)    idx--;

        while(idx){
            if(s[idx-1] !=' '){
                ans++;                
                idx--;
            }
            else
                return ans;
        }


        return ans;
    }
};