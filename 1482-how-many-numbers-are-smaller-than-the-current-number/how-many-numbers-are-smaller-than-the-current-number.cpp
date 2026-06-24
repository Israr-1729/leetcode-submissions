class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int a : nums)
        {
            mp[a]++;
        }

        int size = nums.size();
        vector<int> result(size);

        for(int i = 0; i<size; i++)
        {
            int thisResult = 0;
            int num = nums[i];
            for(auto &a : mp)
            {
                if(a.first<num)
                thisResult+=a.second;
            }
            result[i] = thisResult;
        }
    return result;
    }
};