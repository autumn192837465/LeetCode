/*
	Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

	Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

	Example 1:

	Given nums = [1,1,2],

	Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

	It doesn't matter what you leave beyond the returned length.
	Example 2:

	Given nums = [0,0,1,1,1,2,2,3,3,4],

	Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

	It doesn't matter what values are set beyond the returned length.
	Clarification:

	Confused why the returned value is an integer but your answer is an array?

	Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
*/
// Solution 1
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int cur = nums[0];
        for(vector<int>::iterator  it = (nums.begin()+1);it!=nums.end();it++){
            if(*it != cur){
                cur = *it;
            }
            else{
                nums.erase(it);
                it--;
            }
        }        
        return nums.size();
    }
};
//Solution 2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        
        int i = 0;
        for(int j=1;j<nums.size();j++){
            if(nums[i] != nums[j]){                
                i++;
                nums[i] =nums[j];
            }            
        }        
        return i+1;
    }
};
