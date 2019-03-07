/*
	Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

	Example:

	Given array nums = [-1, 2, 1, -4], and target = 1.

	The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {        
        
        int left;
        int right;
        int dif = INT_MAX;
        int ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){            
            left = i+1;
            right = nums.size()-1;
            while(right > left){
                int rem = nums[i] + nums[right] + nums[left] - target;
                if(abs(rem) < dif){
                    dif = abs(rem);
                    ans = rem + target;
                }
                if(rem > 0) {
                    right --;                    
                }
                else if (rem < 0){
                    left++;
                }
                else{
                    return target;
                }
            }
        }
        return ans;   
    }
};