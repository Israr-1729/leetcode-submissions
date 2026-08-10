class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
        return 0;

        sort(nums.begin(), nums.end());

        int maxGap = INT_MIN;
        
        for(int i = 0; i<nums.size() - 1; i++)
        {
            if(maxGap < (nums[i+1] - nums[i]))
            maxGap = nums[i+1] - nums[i];
        }
        return maxGap;
    }
};