/*
	Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

	This is case sensitive, for example "Aa" is not considered a palindrome here.

	Note:
	Assume the length of given string will not exceed 1,010.

	Example:

	Input:
	"abccccdd"

	Output:
	7

	Explanation:
	One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int tableUpper[26];
        int tableLower[26];
        fill_n(tableUpper,26,0);
        fill_n(tableLower,26,0);
        int ans = 0;
        for(int i =0;i<s.size();i++){
            if(isupper(s[i])){
                tableUpper[s[i] - 'A']++;
            }
            else{
                tableLower[s[i] - 'a']++;
            }
        }
        for(int i = 0;i<26;i++){
            if(tableUpper[i]%2 == 0){
                ans += tableUpper[i];
            }
            else if(ans%2 == 0){
                ans += tableUpper[i];
            }
            else{
                ans += tableUpper[i]-1;
            }

            if(tableLower[i]%2 == 0){
                ans += tableLower[i];
            }
            else if(ans%2 == 0){
                ans += tableLower[i];
            }
            else{
                ans += tableLower[i]-1;
            }
        }
        return ans;
    }
};