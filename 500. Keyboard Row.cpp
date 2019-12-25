/*
	Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

	 



	 
	Example:

	Input: ["Hello", "Alaska", "Dad", "Peace"]
	Output: ["Alaska", "Dad"]
	 

	Note:

	You may use one character in the keyboard more than once.
	You may assume the input string will only contain letters of alphabet.
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for(int i = 0 ;i<words.size();i++){
            if(words[i].size() == 0) {
                ans.push_back(words[i]);
                continue;
            }
            
            int type = FindRow(words[i][0]);
            int j = 1;
            for(;j < words[i].size(); j++){
                if(type != FindRow(words[i][j])){
                    break;
                }
            }
            if(j == words[i].size())    ans.push_back(words[i]);
        }
        return ans;
    }
    int FindRow(char c){
        switch(c){
            case 'q':
            case 'w':
            case 'e':
            case 'r':
            case 't':
            case 'y':
            case 'u':
            case 'i':
            case 'o':
            case 'p':
            case 'Q':
            case 'W':
            case 'E':
            case 'R':
            case 'T':
            case 'Y':
            case 'U':
            case 'I':
            case 'O':
            case 'P':
                return 0;
                break;
            case 'a':
            case 's':
            case 'd':
            case 'f':
            case 'g':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
            case 'A':
            case 'S':
            case 'D':
            case 'F':
            case 'G':
            case 'H':
            case 'J':
            case 'K':
            case 'L':
                return 1;
                break;
            case 'z':
            case 'x':
            case 'c':
            case 'v':
            case 'b':
            case 'n':
            case 'm':
            case 'Z':
            case 'X':
            case 'C':
            case 'V':
            case 'B':
            case 'N':
            case 'M':
                return 2;
                break;
        }
        return 3;
    }
};