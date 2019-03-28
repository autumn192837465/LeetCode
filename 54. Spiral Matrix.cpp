/*
	Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

	Example 1:

	Input:
	[
	 [ 1, 2, 3 ],
	 [ 4, 5, 6 ],
	 [ 7, 8, 9 ]
	]
	Output: [1,2,3,6,9,8,7,4,5]
	Example 2:

	Input:
	[
	  [1, 2, 3, 4],
	  [5, 6, 7, 8],
	  [9,10,11,12]
	]
	Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        if(!matrix.size()) return ans;
        int m = matrix[0].size();
        int n = matrix.size();
        int num = m*n;


        int len = 0;
        int startIdx = 0;
        while(num){
            //right
             for(int i = 0;i<m-len;i++,startIdx++){
                ans.push_back(matrix[startIdx/m][startIdx%m]);
            }
            num -= m - len;
            if(!num){
                return ans;
            }
            startIdx += m - 1;
            len++;

            //down
            for(int i = 0;i<n-len;i++,startIdx+=m){
                ans.push_back(matrix[startIdx/m][startIdx%m]);
            }
            num -= n-len;
            if(!num){
                return ans;
            }
            startIdx -= m + 1;

            //left
            for(int i = 0;i<m-len;i++,startIdx--){
                ans.push_back(matrix[startIdx/m][startIdx%m]);
            }
            num -= m-len;
            if(!num){
                return ans;
            }
            startIdx -= m - 1;
            len ++;

            //up
            for(int i = 0;i<n-len;i++,startIdx-=m){
                ans.push_back(matrix[startIdx/m][startIdx%m]);
            }
            num -= n-len;
            if(!num){
                return ans;
            }
            startIdx += m +1;
        }
        return ans;
    }
};