class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        int currMax = 0;

        for(int i = 0; i < rows-2; i++)
        {
            for(int j = 0; j < columns-2; j++)
            {
                int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

                currMax = max(currMax, sum);
            }
        }
        return currMax;
    }
};