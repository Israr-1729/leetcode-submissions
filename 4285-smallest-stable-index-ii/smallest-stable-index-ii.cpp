class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> maximums(size);
        vector<int> minimums(size);

        int maxm = INT_MIN; int minm = INT_MAX;
        for(int i = 0; i<size; i++)
        {
            maxm = max(maxm, nums[i]);
            maximums[i] = maxm;
        }

        for(int i = size-1; i>=0; i--)
        {
            minm = min(minm, nums[i]);
            minimums[i] = minm;
        }

        for(int i = 0; i<size; i++)
        {
            if(maximums[i]-minimums[i]<=k)
            return i;
        }
        return -1;
    }
};