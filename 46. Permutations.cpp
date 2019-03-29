/*
	Given a collection of distinct integers, return all possible permutations.

	Example:

	Input: [1,2,3]
	Output:
	[
	  [1,2,3],
	  [1,3,2],
	  [2,1,3],
	  [2,3,1],
	  [3,1,2],
	  [3,2,1]
	]
*/
void FindPattern(vector<int> &v,vector<vector<int>> &ans,vector<int> &nums,bool *usedTable,int count){
    if(!count){
        ans.push_back(v);
    }

    for(int i=0;i<nums.size();i++){
        if(!usedTable[i]){
            usedTable[i] = true;
            v.push_back(nums[i]);
            FindPattern(v,ans,nums,usedTable,count-1);
            usedTable[i] = false;
            v.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> v;
        if(!nums.size()){
            ans.push_back(v);
            return ans;
        }
        bool usedTable[nums.size()];
        memset(usedTable,false,sizeof(usedTable));
        FindPattern(v,ans,nums,usedTable,nums.size());
        return ans;
    }
};