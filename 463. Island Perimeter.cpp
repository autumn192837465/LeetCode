/*
	You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

	Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

	The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

	 

	Example:

	Input:
	[[0,1,0,0],
	 [1,1,1,0],
	 [0,1,0,0],
	 [1,1,0,0]]

	Output: 16

	Explanation: The perimeter is the 16 yellow stripes in the image below:
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;

        if(grid.size()){
            // Add wall
            for(int i = 0;i<grid.size();i++){
                grid[i].insert(grid[i].begin(),0);
                grid[i].insert(grid[i].end(),0);
            }
            grid.insert(grid.begin(),vector<int> (grid[0].size(),0));
            grid.insert(grid.end(),vector<int> (grid[0].size(),0));



            for(int i = 1;i<grid.size();i++){
                for(int j = 1;j<grid[0].size();j++){
                    if(grid[i][j]){
                        ans += !grid[i-1][j] + !grid[i][j-1] + !grid[i+1][j] + !grid[i][j+1];
                    }
                }
            }
        }

        return ans;
    }
};