/*
	Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

	Example 1:

	Input: nums = [1,2,3,1], k = 3
	Output: true
	Example 2:

	Input: nums = [1,0,1,1], k = 1
	Output: true
	Example 3:

	Input: nums = [1,2,3,1,2,3], k = 2
	Output: false
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0)  return 0;
        unordered_map<int,int> m;

        for(int i = 0;i<nums.size();i++){
            int n = nums[i];
            if(m.find(n)!=m.end()){
                if(i - m[n] <= k)    return true;
                else m[n] = i;
            }
            else{
                m.insert(make_pair(n,i));
            }
        }
        return false;
    }
};