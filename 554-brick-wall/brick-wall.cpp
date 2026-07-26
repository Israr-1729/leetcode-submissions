class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> mp;
        for(auto &v : wall)
        {
            int size = v.size();
            long long runningSum = 0;
            for(int i = 0; i<size-1; i++)
            {
                runningSum += v[i];
                mp[runningSum]++;
            }
        }

        int highestFrequency = 0;
        for(auto &a : mp)
        {


            highestFrequency = :: max(highestFrequency, a.second);
        }

        return wall.size()-highestFrequency;
        
    }
};