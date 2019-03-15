/*
	Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

	You may assume no duplicates in the array.

	Example 1:

	Input: [1,3,5,6], 5
	Output: 2
	Example 2:

	Input: [1,3,5,6], 2
	Output: 1
	Example 3:

	Input: [1,3,5,6], 7
	Output: 4
	Example 4:

	Input: [1,3,5,6], 0
	Output: 0
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        // start
        int s = 0;
        // end
        int e = n-1;
        int ans = n/2;
        vector<int>::iterator it = nums.begin();
        
        while(s < e){

            if(target == *(it+ans))     return ans;
            else if(target < *(it+ans)) {
                e = ans - 1 ;
                ans = (s + e) /2;
            }
            else {
                s = ans + 1;
                ans = (s+e)/2;
                continue;
            }            
        }

        if(target > *(it + ans)){
            return ans+1;
        }
        else
            return ans;
    }
};