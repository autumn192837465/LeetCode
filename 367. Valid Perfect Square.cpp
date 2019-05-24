/*
	Given a positive integer num, write a function which returns True if num is a perfect square else False.

	Note: Do not use any built-in library function such as sqrt.

	Example 1:

	Input: 16
	Output: true
	Example 2:

	Input: 14
	Output: false
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned int left = 0;
        unsigned int right = num;
        while(left <= right){
            unsigned int mid = (left+right)/2;
            if(mid == (float)num/mid){
                return true;
            }
            else if(left == right){
                return false;
            }


            if(mid > (float)num/mid){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return false;
    }
};