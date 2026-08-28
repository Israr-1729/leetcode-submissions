class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sumP = 0;
        int sumS = 0;
        for(int i = 0; i < mat.size(); i++)
        {
            sumP += mat[i][i];
            sumS += mat[i][mat.size()-i-1];
        }

        if(mat.size() % 2 == 1)
        {
            sumS -= mat[mat.size()/2][mat.size()/2];
        }
        return sumP + sumS;
    }
};