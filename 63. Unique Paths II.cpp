/*
	A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

	The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

	Now consider if some obstacles are added to the grids. How many unique paths would there be?



	An obstacle and empty space is marked as 1 and 0 respectively in the grid.

	Note: m and n will be at most 100.

	Example 1:

	Input:
	[
	  [0,0,0],
	  [0,1,0],
	  [0,0,0]
	]
	Output: 2
	Explanation:
	There is one obstacle in the middle of the 3x3 grid above.
	There are two ways to reach the bottom-right corner:
	1. Right -> Right -> Down -> Down
	2. Down -> Down -> Right -> Right
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(!obstacleGrid.size())    return 0;
        if(!obstacleGrid[0].size())    return 0;
        if(obstacleGrid[0][0] == 1) return 0;


        long pathTable[obstacleGrid[0].size()];
        memset(pathTable,0,sizeof(pathTable));


        pathTable[0] = 1;
        for(int i = 1;i<obstacleGrid[0].size();i++){
            if(obstacleGrid[0][i] == 1){
                pathTable[i] = 0;
            }
            else{
                pathTable[i] = pathTable[i-1];
            }
        }

        for(int i=1;i<obstacleGrid.size();i++){
            for(int j =0;j<obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j] == 0){
                    if(j){
                        pathTable[j] += pathTable[j-1];
                    }
                }
                else{
                    pathTable[j] = 0;
                }
            }
        }
        return pathTable[obstacleGrid[0].size()-1];
    }
};