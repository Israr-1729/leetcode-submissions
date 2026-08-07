class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(auto &a : dominoes)
        {
            if(a[1] > a[0])
            swap(a[1], a[0]);
        }

        unordered_map<string, int> mp;

        for(auto &a : dominoes)
        {
            string newKey = "";
            newKey += to_string(a[0]);
            newKey += "#";
            newKey += to_string(a[1]);

            mp[newKey]++;
        }

        long long ans = 0;

        for(auto &a : mp)
        {
            int k = a.second;
            ans += 1LL * k * (k-1) / 2;
        }
        
        return ans;
    }
};