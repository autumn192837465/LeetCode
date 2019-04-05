/*
	Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

	Example:

	Input: n = 4, k = 2
	Output:
	[
	  [2,4],
	  [3,4],
	  [2,3],
	  [1,2],
	  [1,3],
	  [1,4],
	]
*/
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v(k,0);
        Loop(ans,v,k,n);
        return ans;
    }
    void Loop(vector<vector<int>> &ans,vector<int> &v,int loop,int n){
        if(!loop){
            ans.push_back(v);
            return;
        }
        for(int i = n;i>=loop;i--){
            v[loop-1] = i;
            Loop(ans,v,loop-1,i-1);
        }
    }
};