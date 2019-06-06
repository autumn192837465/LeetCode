/*
	Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

	 

	Example:

	Input:
	[
	 [ 1, 2, 3 ],
	 [ 4, 5, 6 ],
	 [ 7, 8, 9 ]
	]

	Output:  [1,2,4,7,5,3,6,8,9]

	Explanation:

	 

	Note:

	The total number of elements of the given matrix will not exceed 10,000.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(!matrix.size() || !matrix[0].size()) return ans;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0;
        int j = 0;
        ans.push_back(matrix[0][0]);
        // true : goes up
        // false : goes down
        bool dir = true;
        for(int k = 0;k<m*n-1;k++){
            if(dir){
                if(j == n-1){
                    i++;
                    dir = false;
                }
                else if(i==0){
                    j++;
                    dir = false;
                }
                else{
                    i--;
                    j++;
                }
            }
            else{
                if(i == m-1){
                    j++;
                    dir = true;
                }
                else if(j == 0){
                    i++;
                    dir = true;
                }
                else{
                    i++;
                    j--;
                }
            }
            ans.push_back(matrix[i][j]);
        }
        return ans;
    }
};