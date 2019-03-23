/*
	Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

	Your algorithm's runtime complexity must be in the order of O(log n).

	If the target is not found in the array, return [-1, -1].

	Example 1:

	Input: nums = [5,7,7,8,8,10], target = 8
	Output: [3,4]
	Example 2:

	Input: nums = [5,7,7,8,8,10], target = 6
	Output: [-1,-1]
*/
int FindTarget(int left,int right,int target,vector<int> &nums){
    int mid = (left+right)/2;
    if(nums[mid] == target){
        return mid;
    }
    if(left == right)   return -1;

    if(nums[mid] > target){
        return FindTarget(left,mid,target,nums);
    }
    else{
        return FindTarget(mid+1,right,target,nums);
    }

}
int FindNumNotEqualK(int left,int right,int target,vector<int> &nums,bool searchRight){
    // Search right to find the first element not equal to target
    if(left == right)   return  left;
    int mid = (left+right)/2;

    if(searchRight){
        if(nums[mid] == target){
            if(nums[mid+1] != target){
                return mid;
            }
            else{
                return FindNumNotEqualK(mid+1,right,target,nums,true);
            }
        }
        else{
            return FindNumNotEqualK(left,mid,target,nums,true);
        }
    }
    // Search left
    else{
        if(nums[mid]==target){
            if(!mid || nums[mid-1] != target){
                return mid;
            }
            else{
                return FindNumNotEqualK(left,mid,target,nums,false);
            }
        }
        else{
            return FindNumNotEqualK(mid+1,right,target,nums,false);
        }
    }
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() == 0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int idx = FindTarget(0,nums.size()-1,target,nums);

        if(idx == -1){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            ans.push_back(FindNumNotEqualK(0,idx,target,nums,false));
            ans.push_back(FindNumNotEqualK(idx,nums.size()-1,target,nums,true));
        }
        return ans;
    }
};
