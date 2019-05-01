/*
	Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

	Example:

	Input:
	[
	  ["1","0","1","0","0"],
	  ["1","0","1","1","1"],
	  ["1","1","1","1","1"],
	  ["1","0","0","1","0"]
	]
	Output: 6
*/
class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int ans = 0;
        int m = matrix.size();
        if(!m)
            return 0;

        int n = matrix[0].size();

        int height[n];
        int left[n];
        int right[n];

        fill_n(left,n,0);
        fill_n(right,n,n);
        fill_n(height,n,0);

        for(int i = 0; i <m; i++)
        {
            int cur = 0;
            // Max height of matrix [i][j]
            // Left boundry of matrix[i][j]
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '1') {
                    height[j]++;
                    left[j] = max(cur,left[j]);
                }
                else{
                    height[j] = 0;
                    left[j] = 0;
                    cur = j+1;
                }
            }
            cur = n;
            // Right boundry of matrix[i][j]
            for(int j = n-1;j>=0;j--){
                if(matrix[i][j] == '1') right[j] = min(cur,right[j]);
                else {right[j] = n; cur = j;}

                ans = max(ans,(right[j] - left[j])*height[j]);
            }

        }
        return ans;
    }
};