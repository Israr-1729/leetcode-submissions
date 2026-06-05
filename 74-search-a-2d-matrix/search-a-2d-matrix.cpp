class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numOfRows = matrix.size();

        int i = 0;
        while(i<numOfRows && matrix[i][matrix[i].size()-1]<target)
        {
            i++;
        }
        if(i>=numOfRows)
        return false;
        int numOfColumns = matrix[i].size();
        for(int j = 0; j<numOfColumns; j++)
        {
            if(matrix[i][j]==target)
            return true;
        }
        return false;  
    }
};