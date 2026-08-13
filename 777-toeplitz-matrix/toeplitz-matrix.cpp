class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rowIDX = 0; int columnIDX = 0; int rows = matrix.size(); int columns = matrix[0].size();

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(i < rows - 1 && j < columns - 1)
                {
                    if(matrix[i][j] != matrix[i+1][j+1])
                    return false;
                }
            }
        }
        return true;
    }
};