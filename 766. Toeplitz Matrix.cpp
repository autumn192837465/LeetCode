/*
	A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

	Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
	 

	Example 1:

	Input:
	matrix = [
	  [1,2,3,4],
	  [5,1,2,3],
	  [9,5,1,2]
	]
	Output: True
	Explanation:
	In the above grid, the diagonals are:
	"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
	In each diagonal all elements are the same, so the answer is True.
	Example 2:

	Input:
	matrix = [
	  [1,2],
	  [2,2]
	]
	Output: False
	Explanation:
	The diagonal "[1, 2]" has different elements.

	Note:

	matrix will be a 2D array of integers.
	matrix will have a number of rows and columns in range [1, 20].
	matrix[i][j] will be integers in range [0, 99].

	Follow up:

	What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
	What if the matrix is so large that you can only load up a partial row into the memory at once?
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 1;i<matrix.size();i++){
            for(int j = 1;j<matrix[0].size();j++){
                if(matrix[i][j] != matrix[i-1][j-1])    return false;
            }
        }
        return true;
    }
};
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        map<int,int>::iterator iter;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            iter = m.find(target - nums[i]);
            if(iter != m.end()){
                ans.push_back(iter->second);
                ans.push_back(i);
                cout<<ans[0]<<ans[1];
                return ans;
            }
            else{
                m.insert(pair<int,int>(nums[i],i));
            }
        }
        return ans;
    }
};