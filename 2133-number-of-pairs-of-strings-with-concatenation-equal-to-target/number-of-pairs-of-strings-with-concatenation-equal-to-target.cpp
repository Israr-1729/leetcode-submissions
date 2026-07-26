class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int result = 0;
        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            for(int j = i+1; j<size; j++)
            {
                if(nums[i]+nums[j]==target)
                result++;

                if(nums[j]+nums[i]==target)
                result++;
            }
        }
        return result;
    }
};