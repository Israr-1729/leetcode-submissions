class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> mp;
        for(auto &v : wall)
        {
            long long runningSum = 0;
            for(int a : v)
            {
                runningSum += a;
                mp[runningSum]++;
            }
        }

        long long width = 0;
        for(int a : wall[0])
        {
            width += a;
        }

        int highestFrequency = 0;
        for(auto &a : mp)
        {
            if(a.first == width)
            continue;

            highestFrequency = :: max(highestFrequency, a.second);
        }

        return wall.size()-highestFrequency;
        
    }
};