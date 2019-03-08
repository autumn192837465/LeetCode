/*
	The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

	P   A   H   N
	A P L S I I G
	Y   I   R
	And then read line by line: "PAHNAPLSIIGYIR"

	Write the code that will take a string and make this conversion given a number of rows:

	string convert(string s, int numRows);
	Example 1:

	Input: s = "PAYPALISHIRING", numRows = 3
	Output: "PAHNAPLSIIGYIR"
	Example 2:

	Input: s = "PAYPALISHIRING", numRows = 4
	Output: "PINALSIGYAHRPI"
	Explanation:

	P     I    N
	A   L S  I G
	Y A   H R
	P     I
*/
class Solution {
public:
    string convert(string s, int numRows)
    {
        if(numRows == 1)    return s;

        int len = s.size();
        string ans = s;
        int c = 0;
        int newR = numRows-1;
        for(int i = 0; i<numRows; i++)
        {            
            int j = i;
            int last = (i % (newR) == 0)?newR:2 * (newR - i);

            while(j < len){
                ans[c++] = s[j];
                if(i%(newR) != 0){
                    j += last;
                    last = 2 * newR - last;
                }
                else{
                    
                    j+=last;
                }
            }
        }
        return ans;
    }
};
