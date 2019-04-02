/*
	Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

	Each row must contain the digits 1-9 without repetition.
	Each column must contain the digits 1-9 without repetition.
	Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*/
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        bool table[9];
        // Check Coloum
        for(vector<vector<char>>::iterator it = board.begin(); it!=board.end(); it++)
        {
            memset(table,false,sizeof(table));
            for(int i=0; i<9; i++)
            {

                if((*it)[i] == '.')
                    continue;
                if(!table[(*it)[i] - '1'])
                {
                    table[(*it)[i] - '1'] = true;
                }
                else
                {
                    return false;
                }
            }
        }
        // Check Row
        for(int i=0; i<9; i++)
        {
            memset(table,false,sizeof(table));
            for(vector<vector<char>>::iterator it = board.begin(); it!=board.end(); it++)
            {
                if((*it)[i] == '.')
                    continue;
                if(!table[(*it)[i] - '1'])
                {
                    table[(*it)[i] - '1'] = true;
                }
                else
                {
                    return false;
                }
            }
        }
        // Check Block
        for(vector<vector<char>>::iterator it = board.begin(); it!=board.end(); it+=3)
        {
            for(int j=0; j<9; j+=3)
            {
                memset(table,false,sizeof(table));
                for(int k=0; k<3; k++)
                {
                    for(int i=j; i<j+3; i++)
                    {
                        if((*(it+k))[i] == '.')
                            continue;
                        if(!table[(*(it+k))[i] - '1'])
                        {
                            table[(*(it+k))[i] - '1'] = true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }

            }
        }
        return true;
    }
};