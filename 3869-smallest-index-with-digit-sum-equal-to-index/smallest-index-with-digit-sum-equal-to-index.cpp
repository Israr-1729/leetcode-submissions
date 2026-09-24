class Solution {
public:
    int sum(int i)
    {
        int ans = 0;
        while(i)
        {
            ans += i % 10;
            i/=10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == sum(nums[i]))
            return i;
        }
        return -1;
    }
};