class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>result;
        for(int i = 0; i<=rowIndex; i++)
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
        if(rowIndex == 0)
        return {1};

        if(rowIndex == 1)
        return {1,1};
        return result[rowIndex];
    }
};