class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        if(!matrix.size() || !matrix[0].size())  return;
        bool firstColumn = false;
        for(int i = 0; i<matrix.size(); i++)
        {
            if(!matrix[i][0])   firstColumn = true;
            for(int j=1; j<matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }



        for(int i = 1; i<matrix.size(); i++)
        {
            for(int j=1; j<matrix[i].size(); j++)
            {
                if(!matrix[i][0] || !matrix[0][j])
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if(!matrix[0][0]){
            for(int i=1;i<matrix[0].size();i++)
                matrix[0][i] = 0;
        }
        if(firstColumn){
            for(int i=0;i<matrix.size();i++)
                matrix[i][0] = 0;
        }



    }
};