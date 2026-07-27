class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        unordered_set<int> toMakeRows;
        unordered_set<int> toMakeColumns;

        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<columns; j++)
            {
                if(matrix[i][j] == 0)
                {
                    toMakeRows.insert(i);
                    toMakeColumns.insert(j);
                }
            }
        }

        for(auto &a : toMakeRows)
        {
            for(int i = 0; i<columns; i++)
            {
                matrix[a][i] = 0;
            }
        }

        for(auto &a : toMakeColumns)
        {
            for(int i = 0; i<rows; i++)
            {
                matrix[i][a] = 0;
            }
        }
        
    }
};