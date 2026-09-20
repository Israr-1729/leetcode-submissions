class Solution {
public:
    bool allRotten(const vector<vector<int>> &grid)
    {
        for(auto &a : grid)
        {
            for(int i : a)
            {
                if(i == 1)
                return false;
            }
        }
        return true;
    }
    void oneMinute(vector<vector<int>> &grid, const vector<vector<int>> &original)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 2 || grid[i][j] == 0)
                continue;

                if(i > 0 && original[i-1][j] == 2)
                grid[i][j] = 2;
                if(i < rows-1 && original[i+1][j] == 2)
                grid[i][j] = 2;
                if(j > 0 && original[i][j-1] == 2)
                grid[i][j] = 2;
                if(j < cols-1 && original[i][j+1] == 2)
                grid[i][j] = 2;
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        while(!allRotten(grid))
        {
            vector<vector<int>> original = grid;
            oneMinute(grid, original);

            if(original == grid)
            return -1;

            time++;
        }
        return time;
    }
};