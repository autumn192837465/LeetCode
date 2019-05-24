/*
	You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

	Example 1:

	Input:
	  s = "barfoothefoobarman",
	  words = ["foo","bar"]
	Output: [0,9]
	Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
	The output order does not matter, returning [9,0] is fine too.
	Example 2:

	Input:
	  s = "wordgoodgoodgoodbestword",
	  words = ["word","good","best","word"]
	Output: []
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(!s.size() || !words.size())  return ans;
        int len = 0;
        unordered_map<string,int> dict;

        for(auto i : words){
            len+=i.size();
            dict[i]++;
        }


        for(int i = 0;i + len<=s.size();i++){
            unordered_map<string,int> dict2;
            int count = 0;
            for(int j = i;j<i+len ;j+= words[0].size()){
                string str = s.substr(j,words[0].size());

                int wordCount = dict[str];
                if(wordCount){
                    if(++dict2[str] <= wordCount){
                        count++;
                    }
                    else{
                        break;
                    }
                    if(count == len/words[0].size()){
                        ans.push_back(i);
                    }
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};