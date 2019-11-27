/*
	Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

	Find all the elements of [1, n] inclusive that do not appear in this array.

	Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

	Example:

	Input:
	[4,3,2,7,8,2,3,1]

	Output:
	[5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            int idx = abs(nums[i]) - 1;
            nums[idx] = -abs(nums[idx]);
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i] >= 0)    ans.push_back(i + 1);
        }
        return ans;

    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {        
        vector<int> ans;
        if(nums.size()){
            bool n[nums.size()];
            memset(n,false,sizeof(n));
            for(vector<int>::iterator it = nums.begin();it!=nums.end();it++){
                n[*it - 1] = true;
            }
            for(int i = 0;i<nums.size();i++){
                if(!n[i])   ans.push_back(i+1);
            }    
        }        
        return ans;
    }
};