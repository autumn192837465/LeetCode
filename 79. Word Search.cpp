/*
	Given a 2D board and a word, find if the word exists in the grid.

	The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

	Example:

	board =
	[
	  ['A','B','C','E'],
	  ['S','F','C','S'],
	  ['A','D','E','E']
	]

	Given word = "ABCCED", return true.
	Given word = "SEE", return true.
	Given word = "ABCB", return false.
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        if(!m)  return false;
        int n = board[0].size();
        if(!n)  return false;

        vector<vector<bool>> usedTable;
        for(int k =0;k<m;k++){
            usedTable.push_back(vector<bool>(n,false));
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == word[0]){
                    fill(usedTable.begin(),usedTable.end(),vector<bool>(n,false));
                    usedTable[i][j] = true;
                    if(FindWord(m,n,board,usedTable,i,j,0,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool FindWord(int &m,int &n,vector<vector<char>> &board,vector<vector<bool>> &usedTable,int i,int j,int idx,string &word){
        if(idx == word.size()-1)  return true;
        // up
        if(i && !usedTable[i-1][j] && board[i-1][j] == word[idx+1]){
            usedTable[i-1][j] = true;
            if(FindWord(m,n,board,usedTable,i-1,j,idx+1,word)){
                return true;
            }
            usedTable[i-1][j] = false;
        }
        // right
        if(j<n-1 && !usedTable[i][j+1] && board[i][j+1] == word[idx+1]){
            usedTable[i][j+1] = true;
            if(FindWord(m,n,board,usedTable,i,j+1,idx+1,word)){
                return true;
            }
            usedTable[i][j+1] = false;
        }
        // down
        if(i<m-1 && !usedTable[i+1][j] && board[i+1][j] == word[idx+1]){
            usedTable[i+1][j] = true;
            if(FindWord(m,n,board,usedTable,i+1,j,idx+1,word)){
                return true;
            }
            usedTable[i+1][j] = false;
        }
        // left
        if(j && !usedTable[i][j-1] && board[i][j-1] == word[idx+1]){
            usedTable[i][j-1] = true;
            if(FindWord(m,n,board,usedTable,i,j-1,idx+1,word)){
                return true;
            }
            usedTable[i][j-1] = false;
        }
        return false;
    }
};