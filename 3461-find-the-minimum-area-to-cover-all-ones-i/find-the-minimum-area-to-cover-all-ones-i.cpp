class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int maxRow = INT_MIN;
        int minRow = INT_MAX;

        int maxColumn = INT_MIN;
        int minColumn = INT_MAX;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == 1)
                {
                    maxRow = max(maxRow, i);
                    minRow = min(minRow, i);

                    maxColumn = max(maxColumn, j);
                    minColumn = min(minColumn, j);
                }
            }
        }



        cout<<maxRow<<" "<<minRow<<" "<<maxColumn<<" "<<minColumn;

        return(maxRow-minRow + 1)*(maxColumn - minColumn + 1);
        
    }
};