class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int a : nums)
        {
            mp[a]++;
        }

        int result = 0;
        for(auto &a : mp)
        {
            if(a.second == 1)
            result += a.first;
        }
        return result;
    }
};