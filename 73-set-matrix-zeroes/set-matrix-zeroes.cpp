class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<int>> zeroCoordinates;
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<columns; j++)
            {
                if(matrix[i][j] == 0)
                zeroCoordinates.push_back({i, j});
            }
        }

        for(auto &a : zeroCoordinates)
        {
            int makeRow = a[0];
            int makeColumn = a[1];

            for(int i = 0; i<columns; i++)
            {
                matrix[makeRow][i] = 0;
            }

            for(int i = 0; i<rows; i++)
            {
                matrix[i][makeColumn] = 0;
            }
        }
    }
};