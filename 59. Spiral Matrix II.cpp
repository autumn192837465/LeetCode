/*
	Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

	Example:

	Input: 3
	Output:
	[
	 [ 1, 2, 3 ],
	 [ 8, 9, 4 ],
	 [ 7, 6, 5 ]
	]
*/
class Solution {
public:
    int num = 1;
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));

        InsertValue(ans,n,0);

        return ans;
    }

    void InsertValue(vector<vector<int>> &ans,int n,int start){
        if(n <= 0)  return;
        int end = start + n -1;
        // right
        for(int i = start;i<=end;i++)   ans[start][i] = num++;
        //down
        for(int i = start+1;i<end;i++)   ans[i][end] = num++;
        // left
        for(int i = end;i>start;i--)   ans[end][i] = num++;
        //up
        for(int i= end;i>start;i--)    ans[i][start] = num++;

        InsertValue(ans,n-2,start+1);
    }
};
