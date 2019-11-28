/*
	Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
	You receive a valid board, made of only battleships or empty slots.
	Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
	At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
	Example:
	X..X
	...X
	...X
	In the above board there are 2 battleships.
	Invalid Example:
	...X
	XXXX
	...X
	This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
	Follow up:
	Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
*/


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                if(board[i][j] == 'X'){
                    bool left = (j == 0) || board[i][j-1] == '.';
                    bool up = (i == 0) || board[i-1][j] == '.';
                    bool right = (j == board[0].size() - 1) || board[i][j+1] == '.';
                    bool down = (i == board.size() - 1) || board[i+1][j] == '.';
                    // Check invalid
                    if((left & right & !up & !down) || (!left & !right & up & down))    continue;
                    else if((left & right & up & !down) || (left & right & !up & down) || (left & !right & up & down) || (!left & right & up & down))  ans += 1;
                    else if(left & right & up & down)   ans+=2;
                    else return 0;
                }
            }
        }
        return ans/2;
    }
};