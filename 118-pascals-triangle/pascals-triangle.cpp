class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        for(int i = 0; i<numRows; i++)
        {
            vector<int> thisRow(i+1);
            thisRow[0] = 1;
            thisRow[i] = 1;

            for(int j = 1; j<i; j++)
            {
                thisRow[j] = result[i-1][j] + result[i-1][j-1];
            }
            result.push_back(thisRow);
        }
        return result;
    }
};