class NeighborSum {
public:

    vector<vector<int>> g;
    int rowSize;
    int columnSize;
    unordered_map<int, pair<int, int>> valToIndex;
    NeighborSum(vector<vector<int>>& grid) {
        g = grid;
        rowSize = grid.size();
        columnSize = grid[0].size();

        for(int i = 0; i<rowSize; i++)
        {
            for(int j = 0; j<columnSize; j++)
            {
                valToIndex[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int row = valToIndex[value].first;
        int column = valToIndex[value].second;

        int ans = 0;
        if(row > 0)
        ans += g[row - 1][column];

        if(row < rowSize - 1)
        ans += g[row + 1][column];

        if(column > 0)
        ans += g[row][column - 1];

        if(column < columnSize - 1)
        ans += g[row][column + 1];

        return ans;
    }
    
    int diagonalSum(int value) {
        int row = valToIndex[value].first;
        int column = valToIndex[value].second;

        int ans = 0;
        if(row > 0 && column > 0)
        ans += g[row - 1][column - 1];

        if(row > 0 && column < columnSize - 1)
        ans += g[row - 1][column + 1];

        if(row < rowSize - 1 && column > 0)
        ans += g[row+1][column - 1];

        if(row < rowSize - 1 && column < columnSize - 1)
        ans += g[row+1][column + 1];

        return ans;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */