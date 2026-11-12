class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longestStreak = 0;
        int currStreak = 0;
        if(nums.size() == 1)
        return 1;

        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i+1] > nums[i])
            {
                currStreak++;
                longestStreak = max(longestStreak, currStreak);
            }

            else
            {
                currStreak = 0;
            }
        }

        currStreak = 0;

        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i+1] < nums[i])
            {
                currStreak++;
                longestStreak = max(longestStreak, currStreak);
            }

            else
            {
                currStreak = 0;
            }
        }
        return longestStreak + 1;
    }
};