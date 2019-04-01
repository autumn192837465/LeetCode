/*
	Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

	Note: You can only move either down or right at any point in time.

	Example:

	Input:
	[
	  [1,3,1],
	  [1,5,1],
	  [4,2,1]
	]
	Output: 7
	Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        if(grid.size() == 0 || grid[0].size() == 0)     return 0;

        int dp[grid[0].size()];

        dp[0] = grid[0][0];
        // first row
        for(int i = 1;i < grid[0].size();i++){
            dp[i] = dp[i-1] + grid[0][i];
        }

        for(int i= 1;i<grid.size();i++){
            dp[0] += grid[i][0];
            for(int j=1;j<grid[0].size();j++){
                dp[j] = min(dp[j-1],dp[j]) + grid[i][j];
            }
        }
        return dp[grid[0].size()-1];
    }
};