/*
	Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

	'.' Matches any single character.
	'*' Matches zero or more of the preceding element.
	The matching should cover the entire input string (not partial).

	Note:

	s could be empty and contains only lowercase letters a-z.
	p could be empty and contains only lowercase letters a-z, and characters like . or *.
	Example 1:

	Input:
	s = "aa"
	p = "a"
	Output: false
	Explanation: "a" does not match the entire string "aa".
	Example 2:

	Input:
	s = "aa"
	p = "a*"
	Output: true
	Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
	Example 3:

	Input:
	s = "ab"
	p = ".*"
	Output: true
	Explanation: ".*" means "zero or more (*) of any character (.)".
	Example 4:

	Input:
	s = "aab"
	p = "c*a*b"
	Output: true
	Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
	Example 5:

	Input:
	s = "mississippi"
	p = "mis*is*p*."
	Output: false
*/

/*
    Star cases
        case 1
            a* counts 0 time
            dp[i][j] = dp[i][j-2];
            ex:
                aa      dp[2][4] = dp[2][2] if p[3] == "*"
                aaa*
        case 2
            a* counts 1 time
            dp[i][j] = dp[i][j-1];
            ex:
                aa      dp[2][2] = dp[2][1] if p[1] == "*"
                a*
        case 3
            a* counts multi time
            dp[i][j] = dp[i-1][j]
            ex:
                aaa     dp[3][2] = dp[2][2] if p[1] == "*"
                a*
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();
        bool dp[s_len+1][p_len+1];

        memset(dp,0,sizeof(dp));
        dp[0][0] = true;


        // initialize
        for(int i=0;i<=s_len;i++){
            for(int j = 1;j<=p_len;j++){
                if(p[j-1] == '*'){
                    //         0 time        1 time        multi times
                    dp[i][j] = dp[i][j-2] || dp[i][j-1] || (i && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
                else{
                    dp[i][j] = i && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[s_len][p_len];
    }
};