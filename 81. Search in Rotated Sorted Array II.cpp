/*
	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

	(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

	You are given a target value to search. If found in the array return true, otherwise return false.

	Example 1:

	Input: nums = [2,5,6,0,0,1,2], target = 0
	Output: true
	Example 2:

	Input: nums = [2,5,6,0,0,1,2], target = 3
	Output: false
	Follow up:

	This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
	Would this affect the run-time complexity? How and why?
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(!nums.size())    return false;
        else if(nums.size() == 1){
            return nums[0] == target;
        }
        int pivot = 0;
        FindPivot(nums,0,nums.size()-1,pivot);

        int left = 0;
        int right = (pivot == 0)?0:pivot - 1;

        while(true){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(left == right){
                break;
            }
            else if (nums[mid] > target){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        left = pivot;
        right = nums.size()-1;
        while(true){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(left == right){
                break;
            }
            else if (nums[mid] > target){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return false;
    }
    void FindPivot(vector<int>&nums,int left,int right,int &pivot){
        int mid = (left + right)/2;

        if((!mid || nums[mid] < nums[mid-1]) && (mid == nums.size()-1 || nums[mid] <= nums[mid+1])){
            pivot = mid;
            return;
        }
        else if(left == right){
            return;
        }
        else{
            FindPivot(nums,left,mid,pivot);
            if(pivot > 0)
                return;
            FindPivot(nums,mid+1,right,pivot);
            if(pivot > 0)
                return;
        }
    }
};
