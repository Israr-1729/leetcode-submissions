class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            mp[nums[i]]++;
        }

        for(auto &p : mp)
        {
            if(p.second==1)
            return p.first;
        }
        return -1;
    }
};