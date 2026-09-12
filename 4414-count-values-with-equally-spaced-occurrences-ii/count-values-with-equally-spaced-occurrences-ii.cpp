class Solution {
public:

    bool isSpecial(vector<int> &nums)
    {
        int diff = nums[1] - nums[0];
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i+1] - nums[i] != diff)
            return false;
        }
        return true;
    }
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        for(int i = 0; i < nums.size(); i++)
        {
            indices[nums[i]].push_back(i);
        }

        int count = 0;
        for(auto &a : indices)
        {
            if(a.second.size() > 2 && isSpecial(a.second))
            count++;
        }
        return count;
    }
};