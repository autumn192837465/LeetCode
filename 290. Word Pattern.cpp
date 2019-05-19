/*
	Given a pattern and a string str, find if str follows the same pattern.

	Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

	Example 1:

	Input: pattern = "abba", str = "dog cat cat dog"
	Output: true
	Example 2:

	Input:pattern = "abba", str = "dog cat cat fish"
	Output: false
	Example 3:

	Input: pattern = "aaaa", str = "dog cat cat dog"
	Output: false
	Example 4:

	Input: pattern = "abba", str = "dog dog dog dog"
	Output: false
	Notes:
	You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> m;
        stringstream ss(str);
        int i = 0;
        string temp;

        while(getline(ss,temp,' ')){
            map<char,string>::iterator it;
            for(it = m.begin();it!=m.end();it++){
                if(it->second == temp){
                    if(it->first != pattern[i])
                        return false;
                }
            }
            if(it == m.end()){
                it = m.find(pattern[i]);
                if(it == m.end()){
                    m[pattern[i]] = temp;
                }
                else{
                    if(it->second != temp)
                        return false;
                }

            }
            i++;
        }
        if(i != pattern.size()){
            return false;
        }
        return true;
    }
};