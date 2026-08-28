class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i = 0; i < points.size()-1; i++)
        {
            const vector<int> &src = points[i];
            const vector<int> &dst = points[i+1];

            int right = abs(src[0] - dst[0]);
            int down = abs(src[1] - dst[1]);

            time += (min(right, down)) + (max(right, down) - min(right, down));
        }
        return time;
    }
};