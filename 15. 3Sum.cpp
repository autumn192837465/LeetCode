/*
	Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

	Note:

	The solution set must not contain duplicate triplets.

	Example:

	Given array nums = [-1, 0, 1, 2, -1, -4],

	A solution set is:
	[
	  [-1, 0, 1],
	  [-1, -1, 2]
	]
*/
class Solution {
public:
    vector<vector<int> >threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > ans;
        if(n < 3)   return ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){
            if(nums[i] > 0)     break;
            if(i!=0 && nums[i] == nums[i-1])    continue;

            int target = 0 - nums[i];
            int left = i+1;
            int right = n-1;
            while(right > left){
                int rem = target - nums[left]- nums[right];
                if(rem == 0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    ans.push_back(temp);

                    while (left < right && nums[left+1] == nums[left])
                        ++left;
                    while (left < right && nums[right-1] == nums[right])
                        --right;
                    left++;
                    right--;
                }
                else if(rem < 0){
                    right--;
                }
                else{
                    left++;
                }
            }
        }

        return ans;
    }
};