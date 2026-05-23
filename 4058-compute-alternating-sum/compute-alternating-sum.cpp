class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int size = nums.size();
        if(size==0)
        return 0;
        int sum = 0;
        for(int i = 0; i<size; i++)
        {
            if(i%2==0)
            sum+=nums[i];
            else
            sum-=nums[i];
        }
        return sum;
    }
};