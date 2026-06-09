class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxm = INT_MIN;
        long long minm = INT_MAX;
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            maxm = maxm>nums[i] ? maxm : nums[i];
            minm = minm<nums[i] ? minm : nums[i];
        }

        return (maxm-minm)*k;
        
    }
};