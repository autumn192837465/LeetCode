/*
	Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

	If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

	The replacement must be in-place and use only constant extra memory.

	Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

	1,2,3 → 1,3,2
	3,2,1 → 1,2,3
	1,1,5 → 1,5,1
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        for(int i = nums.size()-1;i;i--){
            if(nums[i] > nums[i-1]){
                sort(nums.begin()+i,nums.end());
                for(int j = i;j<nums.size();j++){
                    if(nums[j]>nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        sort(nums.begin() + j,nums.end());
                        return;
                    }
                }
            }
        }
        sort(nums.begin(),nums.end());
        return;
    }
};
