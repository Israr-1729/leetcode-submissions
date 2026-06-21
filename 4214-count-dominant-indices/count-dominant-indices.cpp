class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        vector<int>suffixSum(size);
        for(int i = size-1; i>=0; i--)
        {
            suffixSum[i] = sum;
            sum += nums[i];
        }

        int count = 0;
        for(int i = 0; i<size-1; i++)
        {
            if(nums[i]*(size-i-1)>suffixSum[i])
            count++;
        }
        return count;
    }
};