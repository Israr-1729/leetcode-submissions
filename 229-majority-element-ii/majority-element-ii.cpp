class Solution {
public:

    bool isNotThere(vector<int> result, int num)
    {
        int size = result.size();
        {
            for(int i = 0; i<size; i++)
            {
                if(result[i]==num)
                return false;
            }
        return true;
        }
    }
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<size; i++)
        {
            if(mp.find(nums[i])==mp.end())
            mp[nums[i]] = 0;
            mp[nums[i]]++;
        }
        vector<int> result;
        for(int i = 0; i<size; i++)
        {
            if(mp[nums[i]]>(size/3) && isNotThere(result, nums[i]))
            result.push_back(nums[i]);
        }
        return result;
    }
};