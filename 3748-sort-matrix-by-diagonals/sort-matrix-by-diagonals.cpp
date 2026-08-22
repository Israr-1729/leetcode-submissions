class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int startRow = numRows - 1;

        vector<vector<int>> leftDiagonals;
        while(startRow >= 0)
        {
            int col = 0;
            int row = startRow;
            vector<int> toAdd;
            while(row < numRows)
            {
                toAdd.push_back(grid[row][col]);   
                col++;
                row++;
            }
            leftDiagonals.push_back(toAdd);
            startRow--;
        }

        int startCol = 1;

        vector<vector<int>> rightDiagonals;
        while(startCol < numRows)
        {
            int col = startCol;
            int row = 0;
            vector<int> toAdd;
            while(col < numRows)
            {
                toAdd.push_back(grid[row][col]);
                col++;
                row++;
            }
            rightDiagonals.push_back(toAdd);
            startCol++;
        }

        int numDiagonals = 2 * numRows - 1;

        for(auto &v : leftDiagonals)
        {
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
        }

        for(auto &v : rightDiagonals)
        {
            sort(v.begin(), v.end());
        }

        vector<vector<int>> result (numRows, vector<int> (numRows, 0));

        int leftIdx = 0;
        startRow = numRows - 1;
        while(startRow >= 0)
        {
            int col = 0;
            int row = startRow;
            int idx = 0;

            const vector<int> &thisVector = leftDiagonals[leftIdx++];
            while(row < numRows)
            {
                result[row][col] = thisVector[idx++];
                row++;
                col++;
            }
            startRow--;
        }

        int rightIdx = 0;
        startCol = 1;   
        while(startCol < numRows)
        {
            int col = startCol;
            int row = 0;
            int idx = 0;

            const vector<int> &thisVector = rightDiagonals[rightIdx++];
            while(col < numRows)
            {
                result[row][col] = thisVector[idx++];
                col++;
                row++;
            }
            startCol++;
        }

        
        return result;
    }
};