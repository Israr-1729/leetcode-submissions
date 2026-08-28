class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int lowest = INT_MAX;
        for(auto &a : tasks)
        {
            lowest = min(lowest, a[0] + a[1]);
        }
        return lowest;
    }
};