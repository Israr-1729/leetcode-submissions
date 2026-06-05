class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowOnes(m, 0);
        vector<int> colOnes(n, 0);

        // Count ones in rows and columns
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }

        vector<vector<int>> result(m, vector<int>(n, 0));

        // Build result matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int rowZeros = n - rowOnes[i];
                int colZeros = m - colOnes[j];

                result[i][j] =
                    rowOnes[i] + colOnes[j]
                    - rowZeros - colZeros;
            }
        }

        return result;
    }
};