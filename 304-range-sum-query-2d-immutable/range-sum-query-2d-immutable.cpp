class NumMatrix {
public:

    vector<vector<int>> grid;
    vector<vector<int>> prefixGrid;
    NumMatrix(vector<vector<int>>& matrix) {
        grid = matrix;
        int columns = matrix[0].size();

        for(auto &v : matrix)
        {
            vector<int> thisRowPrefix(columns, 0);
            int runningSum = 0;
            for(int i = 0; i < columns; i++)
            {
                runningSum += v[i];
                thisRowPrefix[i] = runningSum;

            }
            prefixGrid.push_back(thisRowPrefix);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        int ans = 0;
        for(int i = row1; i<=row2; i++)
        {
            if(col1 == 0)
            ans += prefixGrid[i][col2];

            else
            ans += prefixGrid[i][col2] - prefixGrid[i][col1 - 1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */