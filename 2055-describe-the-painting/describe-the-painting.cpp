class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        set<int> keyPoints;
        unordered_map<int, long long> change;
        int minKP = INT_MAX; int maxKP = INT_MIN;

        for(auto &v : segments)
        {
            keyPoints.insert(v[0]);
            keyPoints.insert(v[1]);

            minKP = min(minKP, v[0]);
            maxKP = max(maxKP, v[1]);

            change[v[0]] += v[2];
            change[v[1]] -= v[2];
        }

        vector<int> keys;
        for(int i : keyPoints)
        {
            keys.push_back(i);
        }

        vector<vector<long long>> result;
        long long runningSum = 0;
        for(int i = 0; i < keys.size()-1; i++)
        {
            runningSum += change[keys[i]];

            if(runningSum == 0)
            continue;

            result.push_back({keys[i], keys[i+1], runningSum});
        }
    return result;
    }
};