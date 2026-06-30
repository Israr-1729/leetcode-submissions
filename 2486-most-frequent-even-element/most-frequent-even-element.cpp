class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int a : nums)
        {
            if(a%2 == 0)
            mp[a]++;
        }

        int mostFrequent = -1;
        int highestFrequency = INT_MIN;

        for(auto &p : mp)
        {
            if(p.second>=highestFrequency)
            {
                if(p.second > highestFrequency)
                {
                    mostFrequent = p.first;
                    highestFrequency = p.second;
                }

                else
                {
                    mostFrequent = min(p.first, mostFrequent);
                }
            }
        }
        return mostFrequent;
    }
};