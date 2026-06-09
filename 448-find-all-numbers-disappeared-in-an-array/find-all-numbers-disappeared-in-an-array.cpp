class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        //
        unordered_map<int, bool> mp;
        int size = nums.size();
        for(int i = 1; i<=size; i++)
        {
            mp[nums[i-1]] = true;
        }

        vector<int> result;
        for(int i = 1; i<=size; i++)
        {
            if(!mp[i])
            result.push_back(i);
        }
    return result;
    }
};