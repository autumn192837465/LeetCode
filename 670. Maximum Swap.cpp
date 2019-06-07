/*
	Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

	Example 1:
	Input: 2736
	Output: 7236
	Explanation: Swap the number 2 and the number 7.
	Example 2:
	Input: 9973
	Output: 9973
	Explanation: No swap.
	Note:
	The given number is in the range [0, 108]
*/

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        for(int i = 0;i<numStr.size();i++){
            char maxVal = numStr[i];
            int pos = -1;
            for(int j = numStr.size()-1; j > i;j--){
                if(numStr[j] > maxVal){
                    maxVal = numStr[j];
                    pos = j;
                }
            }
            if(pos >= 0){
                swap(numStr[i],numStr[pos]);
                break;
            }
        }

        return stoi(numStr);
    }
};
