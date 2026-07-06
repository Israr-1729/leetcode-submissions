class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int> &vec1, vector<int> &vec2) {

            if(vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }

            return vec1[0] < vec2[0];
        });

        vector<int> tmpInterval = intervals[0];

        vector<vector<int>> resIntervals;

        for(int i = 1; i < n; i++) {

            if(tmpInterval[0] <= intervals[i][0] && tmpInterval[1] >= intervals[i][1]) {
                continue;
            }

            resIntervals.push_back(tmpInterval);
            tmpInterval = intervals[i];
        }

        return resIntervals.size() + 1;

        
    }
};