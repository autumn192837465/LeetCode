/*
	Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

	Each number in candidates may only be used once in the combination.

	Note:

	All numbers (including target) will be positive integers.
	The solution set must not contain duplicate combinations.
	Example 1:

	Input: candidates = [10,1,2,7,6,1,5], target = 8,
	A solution set is:
	[
	  [1, 7],
	  [1, 2, 5],
	  [2, 6],
	  [1, 1, 6]
	]
	Example 2:

	Input: candidates = [2,5,2,1,2], target = 5,
	A solution set is:
	[
	  [1,2,2],
	  [5]
	]
*/

void FindAns(vector<int> &v,vector<vector<int>> &ans,vector<int> &can,int target,const int idx){
    if(!target){        
        ans.push_back(v);
        return;
    }
    if(target<0 || idx >= can.size())
        return;
    for(int i=idx;i<can.size();i++){
        // Check duplicate
        if(i>idx && can[i]==can[i-1])   continue;
        v.push_back(can[i]);
        FindAns(v,ans,can,target-can[i],i+1);
        v.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        //candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        FindAns(v,ans,candidates,target,0);
        return ans;
    }
};