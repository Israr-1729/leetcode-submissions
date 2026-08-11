class NumMatrix {
public:
    vector<vector<int>> prefixGrid;

    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        prefixGrid.resize(rows + 1, vector<int>(cols + 1, 0));

        for(int i = 1; i <= rows; i++)
        {
            for(int j = 1; j <= cols; j++)
            {
                prefixGrid[i][j] =
                    matrix[i - 1][j - 1]
                    + prefixGrid[i - 1][j]
                    + prefixGrid[i][j - 1]
                    - prefixGrid[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;

        return prefixGrid[row2][col2]
             - prefixGrid[row1 - 1][col2]
             - prefixGrid[row2][col1 - 1]
             + prefixGrid[row1 - 1][col1 - 1];
    }
};