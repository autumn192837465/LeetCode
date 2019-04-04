/*
	Implement int sqrt(int x).

	Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

	Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

	Example 1:

	Input: 4
	Output: 2
	Example 2:

	Input: 8
	Output: 2
	Explanation: The square root of 8 is 2.82842..., and since 
				 the decimal part is truncated, 2 is returned.
*/
int BinarySearch(int left,int right,int &target){
    int mid = (left + right)/2;
    if(target/mid == mid){
        return mid;
    }
    else if(left + 1 == right){
        return left;
    }

    if (target/mid > mid){
        return BinarySearch(mid,right,target);
    }
    else{
        return BinarySearch(left,mid,target);
    }
}
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)  return 0;    

        int temp = 1;
        while(temp < x/temp){
            temp*=10;
        }

        return BinarySearch(max(1,(int)temp/10),temp,x);
    }
};