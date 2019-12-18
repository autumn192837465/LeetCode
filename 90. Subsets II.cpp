/*
	Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

	Note: The solution set must not contain duplicate subsets.

	Example:

	Input: [1,2,2]
	Output:
	[
	  [2],
	  [1],
	  [1,2,2],
	  [2,2],
	  [1,2],
	  []
	]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ans.push_back(vector<int>{});

        for(int i = 0;i<nums.size();){
            int count = 0;
            while(count + i < nums.size() && nums[i] == nums[i + count])    count++;

            for(int j = ans.size() - 1;j >= 0;j--){
                vector<int> v = ans[j];
                for(int k = 0;k<count;k++){
                    v.push_back(nums[i]);
                    ans.push_back(v);
                }
            }
            i+=count;
        }        
        return ans;
    }
};