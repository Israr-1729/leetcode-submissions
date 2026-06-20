class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left -> Right
        for (int i = 1; i < m; i++) {
            int d = restrictions[i][0] - restrictions[i - 1][0];

            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i - 1][1] + d);
        }

        // Right -> Left
        for (int i = m - 2; i >= 0; i--) {
            int d = restrictions[i + 1][0] - restrictions[i][0];

            restrictions[i][1] =
                min(restrictions[i][1],
                    restrictions[i + 1][1] + d);
        }

        int ans = 0;

        // Maximum peak between restrictions
        for (int i = 1; i < m; i++) {

            long long x1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long x2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long d = x2 - x1;

            ans = max(ans,
                     (int)((h1 + h2 + d) / 2));
        }

        // After last restriction, we can keep increasing
        int lastPos = restrictions.back()[0];
        int lastHeight = restrictions.back()[1];

        ans = max(ans,
                 lastHeight + (n - lastPos));

        return ans;
    }
};