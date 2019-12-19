/*
	Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

	You may assume that the array is non-empty and the majority element always exist in the array.

	Example 1:

	Input: [3,2,3]
	Output: 3
	Example 2:

	Input: [2,2,1,1,1,2,2]
	Output: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        unordered_map<int,int> m;

        for(int i = 0;i<nums.size();i++){
            if(m.find(nums[i]) != m.end()){
                m[nums[i]]++;
                if(m[nums[i]] >= (nums.size()+1)/2)   return nums[i];
            }
            else{
                m.insert(make_pair(nums[i],1));
            }
        }
        return 0;
    }
};