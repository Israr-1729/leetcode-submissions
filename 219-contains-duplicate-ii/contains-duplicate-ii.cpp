class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            if(mp.find(nums[i])!=mp.end() && i-mp[nums[i]]<=k)
            return true;

            else if((mp.find(nums[i])!=mp.end() && i-mp[nums[i]]>k))
            {
                mp[nums[i]] = i;
            }

            else
            {
                mp[nums[i]] = i;
            }
        }
    return false;
    
        
    }
};