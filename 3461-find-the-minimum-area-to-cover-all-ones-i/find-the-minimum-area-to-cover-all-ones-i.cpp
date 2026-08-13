class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        set<int> rowIndices;
        set<int> columnIndices;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size() ; j++)
            {
                if(grid[i][j] == 1)
                {
                    rowIndices.insert(i);
                    columnIndices.insert(j);
                }
            }
        }

        int maxRow = *rowIndices.rbegin();
        int minRow = *rowIndices.begin();

        int maxColumn = *columnIndices.rbegin();
        int minColumn = *columnIndices.begin();

        cout<<maxRow<<" "<<minRow<<" "<<maxColumn<<" "<<minColumn;

        return(maxRow-minRow + 1)*(maxColumn - minColumn + 1);
        
    }
};