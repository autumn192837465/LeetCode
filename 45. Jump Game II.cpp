/*
	Given an array of non-negative integers, you are initially positioned at the first index of the array.

	Each element in the array represents your maximum jump length at that position.

	Your goal is to reach the last index in the minimum number of jumps.

	Example:

	Input: [2,3,1,1,4]
	Output: 2
	Explanation: The minimum number of jumps to reach the last index is 2.
		Jump 1 step from index 0 to 1, then 3 steps to the last index.
	Note:

	You can assume that you can always reach the last index.	
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int next = 0;
        int maxStep = 0;
        while(next < nums.size() - 1){
            int cur = next;
            maxStep = cur + nums[cur];
            next = maxStep;
            for(int i = 1; i <= nums[cur] && maxStep < nums.size()-1;i++){
                if(maxStep < cur + i + nums[cur + i]){
                    maxStep = cur + i + nums[cur + i];
                    next = i + cur;
                }
            }
            ans++;
        }
        return ans;
    }
};