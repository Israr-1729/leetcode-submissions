class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numColumns = grid[0].size();
        int heightIncrease = 0;

        for(int i = 0; i<numRows; i++)
        {
            for(int j = 0; j<numColumns; j++)
            {
                int maxRow = INT_MIN; int maxColumn = INT_MIN;
                for(int k = 0; k<numRows; k++)
                {
                    maxRow = max(maxRow, grid[k][j]);
                }
                for(int k = 0; k<numColumns; k++)
                {
                    maxColumn = max(maxColumn, grid[i][k]);
                }

                heightIncrease += min(maxRow, maxColumn) - grid[i][j];
            }
        }
        return heightIncrease;
    }
};