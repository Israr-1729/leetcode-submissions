class Solution {
    int best_finish(vector<int>& a1, vector<int>& d1, vector<int>& a2, vector<int>& d2) {
        int min_end = INT_MAX;
        for (int i = 0; i < (int)a1.size(); ++i)
            min_end = min(min_end, a1[i] + d1[i]);
        
        int ans = INT_MAX;
        for (int i = 0; i < (int)a2.size(); ++i)
            ans = min(ans, max(min_end, a2[i]) + d2[i]);
        
        return ans;
    }
public:
    int earliestFinishTime(
        vector<int>& landStartTime, vector<int>& landDuration,
        vector<int>& waterStartTime, vector<int>& waterDuration
    ) {
        int x = best_finish(landStartTime, landDuration, waterStartTime, waterDuration);
        int y = best_finish(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(x, y);
    }
};