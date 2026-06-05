class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {

        int queriesSize = queries.size();
        int pointsSize = points.size();
        vector<int> result(queriesSize);

        for (int i = 0; i < queriesSize; i++) {
            int num = 0;

            int cx = queries[i][0];
            int cy = queries[i][1];
            long long radiusSquared = 1LL * queries[i][2] * queries[i][2];

            for (int j = 0; j < pointsSize; j++) {
                long long dx = points[j][0] - cx;
                long long dy = points[j][1] - cy;

                long long distanceSquared = dx * dx + dy * dy;

                if (distanceSquared <= radiusSquared)
                    num++;
            }

            result[i] = num;
        }

        return result;
    }
};