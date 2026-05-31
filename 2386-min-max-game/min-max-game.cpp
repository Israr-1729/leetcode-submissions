class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int size = nums.size();
        if(size==1)
        return nums[0];
        vector<int> newNums(size/2);
        int newSize = newNums.size();

        for(int i = 0; i<newSize; i+=2)
        {
            newNums[i] = min(nums[2*i], nums[2*i+1]);
        }
        for(int i = 1; i<newSize; i+=2)
        {
            newNums[i] = max(nums[2*i], nums[2*i+1]);
        }
        return minMaxGame(newNums);
    }
};