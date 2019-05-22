/*
	Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

	Note:
	Both the string's length and k will not exceed 104.

	Example 1:

	Input:
	s = "ABAB", k = 2

	Output:
	4

	Explanation:
	Replace the two 'A's with two 'B's or vice versa.
	Example 2:

	Input:
	s = "AABABBA", k = 1

	Output:
	4

	Explanation:
	Replace the one 'A' in the middle with 'B' and form "AABBBBA".
	The substring "BBBB" has the longest repeating letters, which is 4.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26,0);
        int count = 0;
        int ans = 0;
        int left = -1;
        for(int i = 0;i<s.size();i++){
            v[s[i] - 'A']++;
            count = max(v[s[i] - 'A'],count);
            while(i - left > count + k){
                left++;
                v[s[left]-'A']--;
                count = *max_element(v.begin(),v.end());
            }
            ans = max(ans,i - left);
        }
        return ans;
    }
};