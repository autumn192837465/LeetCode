/*
	Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

	Example 1:

	Input: S = "loveleetcode", C = 'e'
	Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
	 

	Note:

	S string length is in [1, 10000].
	C is a single character, and guaranteed to be in string S.
	All letters in S and C are lowercase.
*/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> v;
        vector<int> ans(S.size());
        for(int i = 0;i<S.size();i++){
            if(S[i] == C){
                v.push_back(i);
            }
        }

        // to first char
        for(int i = 0;i<v[0];i++){
            ans[i] = v[0] - i;
        }
        // middle
        for(int i = v[0] + 1,last = 0;last < v.size()-1 ;i++){
            ans[i] = min(i - v[last], v[last+1] - i);
            if(i == v[last+1]){
                last++;                
            }
        }
        // last
        for(int i = v[v.size()-1] + 1;i<S.size();i++){
            ans[i] = i - v[v.size()-1];
        }


        return ans;
    }
};