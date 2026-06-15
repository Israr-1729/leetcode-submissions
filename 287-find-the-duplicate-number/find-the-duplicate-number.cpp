class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int a : nums)
        {
            if(mp[a]==true)
            return a;
            mp[a] = true;
        }
        return -1;
    }
};