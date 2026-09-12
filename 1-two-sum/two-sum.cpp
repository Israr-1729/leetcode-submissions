class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        int idx = 0;
        for(int i : nums)
        {
            if(s.contains(target-i))
            return {idx, s[target-i]};

            s[i] = idx;
            idx++;
        }
        return {};
    }
};