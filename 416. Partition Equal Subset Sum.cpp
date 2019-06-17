/*
	Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

	Note:

	Each of the array element will not exceed 100.
	The array size will not exceed 200.
	 

	Example 1:

	Input: [1, 5, 11, 5]

	Output: true

	Explanation: The array can be partitioned as [1, 5, 5] and [11].
	 

	Example 2:

	Input: [1, 2, 3, 5]

	Output: false

	Explanation: The array cannot be partitioned into equal sum subsets.
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),0);

        if(sum%2 == 1)  return false;
        sum>>=1;

        bool dp[sum + 1];
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        int cur = 0;

        for(vector<int>::iterator it = nums.begin();it!=nums.end();it++){
            if(dp[sum]) return true;
            for(int i = sum; i >= (*it);i--){
                dp[i] = dp[i] | dp[i-(*it)];
            }
        }

        return dp[sum];
    }

};