/*
	Write a program to find the n-th ugly number.

	Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

	Example:

	Input: n = 10
	Output: 12
	Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
	Note:  

	1 is typically treated as an ugly number.
	n does not exceed 1690.
*/

class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> uglyV{1};
        int i = 0;
        int j = 0;
        int k = 0;
        while(uglyV.size() != n){
            uglyV.push_back(min(uglyV[i]*2,min(uglyV[j]*3,uglyV[k]*5)));
            if(uglyV.back() == uglyV[i]*2)  i++;
            if(uglyV.back() == uglyV[j]*3)  j++;
            if(uglyV.back() == uglyV[k]*5)  k++;
        }
        return uglyV[n-1];
    }
};