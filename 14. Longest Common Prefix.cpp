<<<<<<< HEAD
/*
	Write a function to find the longest common prefix string amongst an array of strings.

	If there is no common prefix, return an empty string "".

	Example 1:

	Input: ["flower","flow","flight"]
	Output: "fl"
	Example 2:

	Input: ["dog","racecar","car"]
	Output: ""
	Explanation: There is no common prefix among the input strings.
	Note:

	All given inputs are in lowercase letters a-z.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)    return "";
        string ans = strs[0];
        int idx = 0;

        for(vector<string>::iterator it= strs.begin()+1;it!=strs.end();it++){
            for(int i=0;i<ans.size()&&i<(*it).size();i++){
                if((*it)[i] != ans[i]){
                    ans = (*it).substr(0,i);
                    break;
                }
            }
        }
        return ans;
    }
=======
/*
	Write a function to find the longest common prefix string amongst an array of strings.

	If there is no common prefix, return an empty string "".

	Example 1:

	Input: ["flower","flow","flight"]
	Output: "fl"
	Example 2:

	Input: ["dog","racecar","car"]
	Output: ""
	Explanation: There is no common prefix among the input strings.
	Note:

	All given inputs are in lowercase letters a-z.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)    return "";
        string ans = strs[0];
        int idx = 0;

        for(vector<string>::iterator it= strs.begin()+1;it!=strs.end();it++){
            for(int i=0;i<ans.size()&&i<(*it).size();i++){
                if((*it)[i] != ans[i]){
                    ans = (*it).substr(0,i);
                    break;
                }
            }
        }
        return ans;
    }
>>>>>>> 644f4db57ca5adf67612352327d0b33403ce724b
};