/*
	Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
	Example 1:
	Input: [2,2,3,4]
	Output: 3
	Explanation:
	Valid combinations are: 
	2,3,4 (using the first 2)
	2,3,4 (using the second 2)
	2,2,3
	Note:
	The length of the given array won't exceed 1000.
	The integers in the given array are in the range of [0, 1000].
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(),nums.end());
        int ans = 0;

        for(int i = 0;i<nums.size() - 2;i++){
            if(nums[i]==0)  continue;
            int k = i + 2;
            for(int j = i + 1;j<nums.size() - 1;j++){
                for(;k<nums.size();k++){
                    if(nums[i] + nums[j] <= nums[k]){
                        break;
                    }
                }
                ans += k-j-1;
            }
        }
        return ans;
    }
};