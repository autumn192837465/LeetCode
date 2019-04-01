/*
	Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

	Integers in each row are sorted from left to right.
	The first integer of each row is greater than the last integer of the previous row.
	Example 1:

	Input:
	matrix = [
	  [1,   3,  5,  7],
	  [10, 11, 16, 20],
	  [23, 30, 34, 50]
	]
	target = 3
	Output: true
	Example 2:

	Input:
	matrix = [
	  [1,   3,  5,  7],
	  [10, 11, 16, 20],
	  [23, 30, 34, 50]
	]
	target = 13
	Output: false
*/

bool BinartSearch(vector<int> &m,int &tar,int left,int right){
    int mid = (left + right)/2;

    if(m[mid] == tar){
        return true;
    }
    else if(left == right){
        return false;
    }

    if(m[mid] < tar){
        return BinartSearch(m,tar,mid+1,right);
    }
    else{
        return BinartSearch(m,tar,left,mid);
    }
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0;i<matrix.size();i++){
            if(matrix[i].size() && BinartSearch(matrix[i],target,0,matrix[i].size()-1))
                return true;
        }
        return false;
    }
};