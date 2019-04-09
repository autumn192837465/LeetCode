/*
	Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

	The same repeated number may be chosen from candidates unlimited number of times.

	Note:

	All numbers (including target) will be positive integers.
	The solution set must not contain duplicate combinations.
	Example 1:

	Input: candidates = [2,3,6,7], target = 7,
	A solution set is:
	[
	  [7],
	  [2,2,3]
	]
	Example 2:

	Input: candidates = [2,3,5], target = 8,
	A solution set is:
	[
	  [2,2,2,2],
	  [2,3,3],
	  [3,5]
	]	
*/
void FindTarget(vector<int> &v,vector<vector<int>>& ans,vector<int>& can,int target,int idx){    
    if(!target){
        ans.push_back(v);
        return;
    }
    if(can[idx] > target) return;

    for(int i=idx;i<can.size();i++){
        v.push_back(can[i]);
        FindTarget(v,ans,can,target-can[i],i);
        v.pop_back();
    }
}



class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0)  return ans;
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        FindTarget(v,ans,candidates,target,0);
        return ans;
    }
};
