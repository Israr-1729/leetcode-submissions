class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        long long sum = 0;
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            sum+=nums[i];
        }
        vector<int> leftSum(size, 0);
        vector<int> rightSum(size, 0);

        leftSum[0] = 0; 
        for(int i = 1; i<size; i++)
        {
            leftSum[i] = leftSum[i-1] + nums[i-1]; 
        }
        rightSum[0] = sum-nums[0];
        for(int i = 1; i<size; i++)
        {
            rightSum[i] = rightSum[i-1] - nums[i];
        }

        vector<int> result(size);
        for(int i = 0; i<size; i++)
        {
            result[i] = abs(leftSum[i] - rightSum[i]);
        }
        return result;
    }
};