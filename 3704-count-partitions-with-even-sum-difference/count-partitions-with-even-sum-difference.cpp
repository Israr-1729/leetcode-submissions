class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long totalSum = 0;
        for(int i : nums)
        {
            totalSum += i;
        }

        long long leftSum = 0;
        int count = 0;

        for(int i = 0; i < nums.size()-1; i++)
        {
            leftSum += nums[i];
            int rightSum = totalSum - leftSum;

            if((leftSum%2 == rightSum%2))
            count++;
        }
        return count;
    }
};