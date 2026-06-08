class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int size = nums.size();

        vector<int> leftSum(size,0);
        vector<int> rightSum(size,0);

        int left = 0;
        for(int i = 0; i<size; i++)
        {
            leftSum[i] = left;
            left+= nums[i];
        }
        int right = 0;
        for(int i = size-1; i>=0; i--)
        {
            rightSum[i] = right;
            right+= nums[i];
        }

        for(int i = 0; i<size; i++)
        {
            if(leftSum[i]==rightSum[i])
            return i;
        }
        return -1;
        
    }
};