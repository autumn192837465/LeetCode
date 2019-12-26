/*
	Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
	Example:
	Input: s = "abcdefg", k = 2
	Output: "bacdfeg"
	Restrictions:
	The string consists of lower English letters only.
	Length of the given string and k will in the range [1, 10000]
*/

class Solution {
public:
    string reverseStr(string s, int k) {

        int idx = 0;

        for(;idx + 2 * k < (s.size());idx +=2 * k){
            for(int j = 0;j<k/2;j++){
                swap(s[idx + j],s[idx + k - 1 - j]);
            }
        }

        if(s.size() - idx >= k){
            for(int i = 0;i<k/2;i++){
                swap(s[idx + i],s[idx + k - 1 - i]);
            }
        }
        else{
            for(int i = 0;i < (s.size() - idx)/2;i++){
                swap(s[idx + i],s[s.size() - i - 1]);
            }
        }
        return s;
    }
};