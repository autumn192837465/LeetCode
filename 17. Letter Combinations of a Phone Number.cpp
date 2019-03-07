/*
	Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

	A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


	Example:

	Input: "23"
	Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
	
	1: 1
	2: a,b,c
	3: d,e,f
	4: g,h,i
	5: j,k,l
	6: m,n,o
	7: p,q,r,s
	8: t,u,v
	9:w,x,y,z
	0: space
*/
void BackTrack(string cur,string &digits,int idx,vector<string>&ans){
    if(idx == digits.size()){
        if(idx != 0)
            ans.push_back(cur);
        return;
    }
    switch(digits[idx]){
        case '0':
            BackTrack(cur + " ",digits,idx+1,ans);
            break;
        case '1':
            BackTrack(cur + "*",digits,idx+1,ans);
            break;
        case '2':
            BackTrack(cur + "a",digits,idx+1,ans);
            BackTrack(cur + "b",digits,idx+1,ans);
            BackTrack(cur + "c",digits,idx+1,ans);
            break;
        case '3':
            BackTrack(cur + "d",digits,idx+1,ans);
            BackTrack(cur + "e",digits,idx+1,ans);
            BackTrack(cur + "f",digits,idx+1,ans);
            break;
        case '4':
            BackTrack(cur + "g",digits,idx+1,ans);
            BackTrack(cur + "h",digits,idx+1,ans);
            BackTrack(cur + "i",digits,idx+1,ans);
            break;
        case '5':
            BackTrack(cur + "j",digits,idx+1,ans);
            BackTrack(cur + "k",digits,idx+1,ans);
            BackTrack(cur + "l",digits,idx+1,ans);
            break;
        case '6':
            BackTrack(cur + "m",digits,idx+1,ans);
            BackTrack(cur + "n",digits,idx+1,ans);
            BackTrack(cur + "o",digits,idx+1,ans);
            break;
        case '7':
            BackTrack(cur + "p",digits,idx+1,ans);
            BackTrack(cur + "q",digits,idx+1,ans);
            BackTrack(cur + "r",digits,idx+1,ans);
            BackTrack(cur + "s",digits,idx+1,ans);
            break;
        case '8':
            BackTrack(cur + "t",digits,idx+1,ans);
            BackTrack(cur + "u",digits,idx+1,ans);
            BackTrack(cur + "v",digits,idx+1,ans);
            break;
        case '9':
            BackTrack(cur + "w",digits,idx+1,ans);
            BackTrack(cur + "x",digits,idx+1,ans);
            BackTrack(cur + "y",digits,idx+1,ans);
            BackTrack(cur + "z",digits,idx+1,ans);
            break;
        default:
            BackTrack(cur,digits,idx+1,ans);
            break;
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        BackTrack("",digits,0,ans);
        return ans;
    }
};
