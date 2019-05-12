/*
	Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

	Example:

	Input: 2
	Output: 91 
	Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
				 excluding 11,22,33,44,55,66,77,88,99
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)  return 1;
        int ans = 1;
        for(int i = 1;i<=n;i++){
            int temp = 9;
            for(int j=1;j<i;j++){
                temp *= (10-j);
            }
            ans += temp;
        }
        return ans;
    }
};
