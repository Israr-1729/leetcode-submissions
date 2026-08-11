class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> copy;
        for(int a : nums)
        {
            copy.insert(a);
        }

        int maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1] + 1)
            maxSum += nums[i];

            else
            break;
        }

        int ans = maxSum;
        cout<<maxSum;
        for(int i = maxSum; i>=-1; i++)
        {
            if(!copy.contains(i))
            {
                ans = i;
                break;
            }
        }

        return ans;
    }
};