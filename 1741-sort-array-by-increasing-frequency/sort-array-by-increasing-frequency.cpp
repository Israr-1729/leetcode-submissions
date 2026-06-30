class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> freq(size + 1);
        unordered_map<int, int> mp;
        for(int a : nums)
        {
            mp[a]++;
        }

        for(auto &p : mp)
        {
            freq[p.second].push_back(p.first);
        }

        for(auto &v : freq)
        {
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
        }

        vector<int> result;
        for(int i = 1; i<freq.size(); i++)
        {
            const vector<int> &v = freq[i];
            for (int a : v) 
            {
                for(int j = 0; j<i; j++)
                result.push_back(a);
            }
        }
        return result;
    }
};