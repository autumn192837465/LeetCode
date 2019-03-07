/*
	Given a string, find the length of the longest substring without repeating characters.

	Example 1:

	Input: "abcabcbb"
	Output: 3 
	Explanation: The answer is "abc", with the length of 3. 
	Example 2:

	Input: "bbbbb"
	Output: 1
	Explanation: The answer is "b", with the length of 1.
	Example 3:

	Input: "pwwkew"
	Output: 3
	Explanation: The answer is "wke", with the length of 3. 
				 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        int startIdx = 0;
        int ans = 0;

        // hash table
        bool ht[256] = {false}; //97
        int accum = 0;
        for(int i=0;i<s.size();i++){
            int key = (int)s[i];
            //cout<<"Cur : " << s[i] <<endl;
            if(!ht[key]){
                ht[key] = true;
            }
            else{
                ans = (ans> i - startIdx)?ans:i-startIdx;
                //cout<< "start idx : "<<startIdx<<" end idx : "<<i<<endl;
                while(s[startIdx] != s[i]){
                    ht[(int)s[startIdx]] = false;
                    startIdx ++;
                }
                startIdx ++;
                //cout<<"new start idx : "<< startIdx << endl;
            }
        }
        ans = (ans> s.size() - startIdx)?ans:s.size()-startIdx;
        return ans;
    }
};
