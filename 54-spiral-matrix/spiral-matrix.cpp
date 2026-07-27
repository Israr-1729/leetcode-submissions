class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        int tillRow = rows-1;
        int tillColumn = columns-1;

        int startRow = 0;
        int startColumn = 0;

        vector<int> result;

        while (startRow <= tillRow && startColumn <= tillColumn)        
        {
            //left to right
            for(int i = startColumn; i<=tillColumn; i++)
            result.push_back(matrix[startRow][i]);
            startRow++;

            if (startRow > tillRow) break;
            if (startColumn > tillColumn) break;


            //top to bottom
            for(int i = startRow; i<=tillRow; i++)
            result.push_back(matrix[i][tillColumn]);
            tillColumn--;

            if (startRow > tillRow) break;
            if (startColumn > tillColumn) break;

            //right to left
            for(int i = tillColumn; i>=startColumn; i--)
            result.push_back(matrix[tillRow][i]);
            tillRow--;

            if (startRow > tillRow) break;
            if (startColumn > tillColumn) break;

            //bottom to top
            for(int i = tillRow; i>=startRow; i--)
            result.push_back(matrix[i][startColumn]);
            startColumn++;

            if (startRow > tillRow) break;
            if (startColumn > tillColumn) break;
        }
        return result;
    }
};