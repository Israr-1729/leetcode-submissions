class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int>mp;
        for(auto &a : nums1)
        {
            mp[a[0]] += a[1];
        }
        for(auto &a : nums2)
        {
            mp[a[0]] += a[1];
        }
        
        vector<vector<int>> result;
        for(auto &a : mp)
        result.push_back({a.first, a.second});
        return result;
    }
};