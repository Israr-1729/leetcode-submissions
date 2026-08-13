class Solution {
public:
    unordered_map<int, vector<int>> numToIndices;
    Solution(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++)
        {
            numToIndices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        const vector<int> &v = numToIndices[target];
        return v[rand() % v.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */