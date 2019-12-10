/*
	You are given a string representing an attendance record for a student. The record only contains the following three characters:
	'A' : Absent.
	'L' : Late.
	'P' : Present.
	A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

	You need to return whether the student could be rewarded according to his attendance record.

	Example 1:
	Input: "PPALLP"
	Output: True
	Example 2:
	Input: "PPALLL"
	Output: False
*/

class Solution {
public:
    bool checkRecord(string s) {
        int Acount = 0;
        int Lcount = 0;
        for(int i = 0;i<s.length();i++){
            switch(s[i]){
                case 'A':
                    Acount ++;
                    if(Acount == 2) return false;
                    Lcount = 0;
                    break;
                case 'L':
                    Lcount ++;
                    if(Lcount == 3) return false;
                    break;
                case 'P':
                    Lcount = 0;
                    break;
            }
        }
        return true;
    }
};