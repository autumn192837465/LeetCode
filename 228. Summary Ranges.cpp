/*
	Given a sorted integer array without duplicates, return the summary of its ranges.

	Example 1:

	Input:  [0,1,2,4,5,7]
	Output: ["0->2","4->5","7"]
	Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
	Example 2:

	Input:  [0,2,3,4,6,8,9]
	Output: ["0","2->4","6","8->9"]
	Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(!nums.size())    return ans;
        nums.push_back(nums[nums.size()-1]-1);
        int start = nums[0];
        bool continuous = false;
        for(int i =1;i<nums.size();i++){
            if(nums[i-1] != nums[i]-1){
                if(!continuous){
                    ans.push_back(to_string(start));
                }
                else{
                    ans.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                    continuous = false;
                }
                start = nums[i];
            }
            else{
                continuous = true;
            }
        }
        return ans;
    }
};