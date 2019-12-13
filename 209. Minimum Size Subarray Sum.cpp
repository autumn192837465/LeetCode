/*
	Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

	Example: 

	Input: s = 7, nums = [2,3,1,2,4,3]
	Output: 2
	Explanation: the subarray [4,3] has the minimal length under the problem constraint.
	Follow up:
	If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = nums.size() + 1;
        int sum = 0;
        int left = 0,right = 0;

        while(left < nums.size()){
            if(sum >= s ){
                ans = min(ans,right-left);
                sum -= nums[left++];
                continue;
            }
            if(right == nums.size()){
                sum -= nums[left++];
            }
            // right++
            else if(sum < s){
                sum += nums[right++];
            }
        }
        return (ans <= nums.size())?ans:0;
    }
};
