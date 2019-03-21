/*
	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

	(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

	You are given a target value to search. If found in the array return its index, otherwise return -1.

	You may assume no duplicate exists in the array.

	Your algorithm's runtime complexity must be in the order of O(log n).

	Example 1:

	Input: nums = [4,5,6,7,0,1,2], target = 0
	Output: 4
	Example 2:

	Input: nums = [4,5,6,7,0,1,2], target = 3
	Output: -1
*/
int FindTarget(vector<int>& n,int t,int left,int right){
    if(left == right){
        return (n[right]==t)?right:-1;
    }

    int mid = (left+right)/2;
    if(n[mid] == t){
        return mid;
    }
    else if(n[mid] > t){
        return FindTarget(n,t,left,mid);
    }
    else{
        return FindTarget(n,t,mid+1,right);
    }
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(nums.size()==0)  return -1;

        int endIdx = len-1;
        for(int i=1;i<len;i++){
            if(nums[i]<nums[i-1]){
                endIdx = i-1;
                break;
            }
        }
        if(endIdx == len-1){
            return FindTarget(nums,target,0,len-1);
        }        
        return max(FindTarget(nums,target,0,endIdx),FindTarget(nums,target,endIdx+1,len-1));
    }
};