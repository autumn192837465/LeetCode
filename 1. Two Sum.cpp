/*
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        map<int,int>::iterator iter;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            iter = m.find(target - nums[i]);
            if(iter != m.end()){
                ans.push_back(iter->second);
                ans.push_back(i);
                cout<<ans[0]<<ans[1];
                return ans;
            }
            else{
                m.insert(pair<int,int>(nums[i],i));
            }
        }
        return ans;
    }
};