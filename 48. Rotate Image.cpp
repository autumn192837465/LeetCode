/*
	You are given an n x n 2D matrix representing an image.

	Rotate the image by 90 degrees (clockwise).

	Note:

	You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

	Example 1:

	Given input matrix = 
	[
	  [1,2,3],
	  [4,5,6],
	  [7,8,9]
	],

	rotate the input matrix in-place such that it becomes:
	[
	  [7,4,1],
	  [8,5,2],
	  [9,6,3]
	]
	Example 2:

	Given input matrix =
	[
	  [ 5, 1, 9,11],
	  [ 2, 4, 8,10],
	  [13, 3, 6, 7],
	  [15,14,12,16]
	], 

	rotate the input matrix in-place such that it becomes:
	[
	  [15,13, 2, 5],
	  [14, 3, 4, 1],
	  [12, 6, 8, 9],
	  [16, 7,10,11]
	]
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return;
        Rotation(matrix,0,matrix[0].size());
    }
    void Rotation(vector<vector<int>> &m,int s,int n){
        if(n<= 0)return;

        int e = s + n - 1;
        vector<int> temp = vector<int>(m[s].begin()+s,m[s].end()-s);

        // left -> up
        for(int i = s;i<e;i++)
            m[s][i] = m[e + s - i][s];
        // down -> left
        for(int i = e;i>s;i--)
            m[i][s] = m[e][i];
        // right -> down
        for(int i = s;i<e;i++)
            m[e][i] = m[e + s - i][e];
        // temp -> right
        for(int i = 0;i<n;i++)
            m[s+i][e] = temp[i];

        Rotation(m,s+1,n-2);
    }
};