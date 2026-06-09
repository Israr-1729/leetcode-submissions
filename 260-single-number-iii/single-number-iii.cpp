class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        map<int, int> mp;
        for(int i = 0; i<size; i++)
        {
            mp[nums[i]]++;
        }
        vector<int> result;
        for(auto &p : mp)
        {
            if(p.second==1)
            result.push_back(p.first);
        }
        return result;
    }
};