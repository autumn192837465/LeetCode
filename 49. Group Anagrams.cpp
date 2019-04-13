/*
	Given an array of strings, group anagrams together.

	Example:

	Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
	Output:
	[
	  ["ate","eat","tea"],
	  ["nat","tan"],
	  ["bat"]
	]
	Note:

	All inputs will be in lowercase.
	The order of your output does not matter.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        if(strs.size() == 0)    return ans;


        int countTable[26];
        string strTable[strs.size()];


        for(int i=0;i<strs.size();i++){
            memset(countTable,0,sizeof(countTable));
            for(int j=0;j<strs[i].size();j++){
                countTable[strs[i][j] - 'a'] ++;
            }
            for(int j=0;j<26;j++)
                strTable[i] += "#" + to_string(countTable[j]);
            //cout<<strTable[i]<<endl;
        }

        map<string,int> mapTable;
        map<string,int>::iterator it;
        int count = 0;
        for(int i=0;i<strs.size();i++){
            it = mapTable.find(strTable[i]);
            if(it == mapTable.end()){
                mapTable.insert( make_pair(strTable[i],count++));
                ans.push_back(vector<string>{strs[i]});
            }
            else{
                ans[it->second].push_back(strs[i]);
            }
        }


        return ans;
    }
};