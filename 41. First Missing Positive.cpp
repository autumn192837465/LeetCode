/*
	Given an unsorted integer array, find the smallest missing positive integer.

	Example 1:

	Input: [1,2,0]
	Output: 3
	Example 2:

	Input: [3,4,-1,1]
	Output: 2
	Example 3:

	Input: [7,8,9,11,12]
	Output: 1
	Note:

	Your algorithm should run in O(n) time and uses constant extra space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {        
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size()-1;
        bool flag = false;
        for(int i =0;i<nums.size();i++){
            if(nums[i] > 0){
                if(!flag){
                    if(nums[i]!=1)
                        return 1;
                    else{
                        flag = true;
                    }
                }
                else{
                    if(nums[i] - nums[i-1] >1){
                        return nums[i-1] + 1;
                    }
                }
            }
        }
        if(!flag)
            return 1;
        else
            return nums[nums.size()-1]+1;
    }
};
