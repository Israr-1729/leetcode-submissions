class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxm = INT_MIN;
        int minm = INT_MAX;

        int size = nums.size();
        for(int i = 0; i<size; i++)
        {
            maxm = max(maxm, nums[i]);
            minm = min(minm, nums[i]);
        }
        int counter = 0;
        for(int i = 0; i<size; i++)
        {
            if(nums[i]<maxm && nums[i]>minm)
            counter++;
        }
        return counter;
    }
};