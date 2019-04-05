/*
	Given a set of distinct integers, nums, return all possible subsets (the power set).

	Note: The solution set must not contain duplicate subsets.

	Example:

	Input: nums = [1,2,3]
	Output:
	[
	  [3],
	  [1],
	  [2],
	  [1,2,3],
	  [1,3],
	  [2,3],
	  [1,2],
	  []
	]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i = 0;i<nums.size();i++){
            vector<int> v(i+1,0);
            Recursive(ans,v,nums,i,nums.size()-1);
        }
        return ans;
    }
    void Recursive(vector<vector<int>> &ans, vector<int> &v,vector<int> &nums,int n,int idx){
        if(n < 0){
            ans.push_back(v);
            return;
        }
        for(int i = idx;i>=n;i--){
            v[n] = nums[i];
            Recursive(ans,v,nums,n-1,i-1);
        }
    }
};