/*
	Given a string s, partition s such that every substring of the partition is a palindrome.

	Return all possible palindrome partitioning of s.

	Example:

	Input: "aab"
	Output:
	[
	  ["aa","b"],
	  ["a","a","b"]
	]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        BackTracking(ans,0,s,v);


        return ans;
    }
    void BackTracking(vector<vector<string>> &ans,int idx,string &s,vector<string> &v){
        if(idx == s.size()){
            ans.push_back(v);
            return;
        }
        for(int i = idx;i<s.size();i++){

            if(CheckPartition(s.substr(idx,i-idx+1))){
                v.push_back(s.substr(idx,i-idx+1));
                BackTracking(ans,i+1,s,v);
                v.pop_back();
            }
        }
    }

    bool CheckPartition(string s){
        for(int i = 0;i<s.size()/2;i++){
            if(s[i] != s[s.size()-1-i]) return false;
        }
        return true;
    }
};