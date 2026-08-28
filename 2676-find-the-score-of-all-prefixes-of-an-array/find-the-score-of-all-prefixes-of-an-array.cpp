class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> result(nums.size(), 0);
        int maxm = INT_MIN;
        long long runningSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            maxm = max(maxm, nums[i]);
            runningSum += nums[i] + maxm;
            result[i] = runningSum;
        }
        return result;
    }
};