class Solution {
public:
    int triangularSum(vector<int>& nums) {

        int size = nums.size();
        if(size==1)
        return nums[0];

        vector<int> newArr(size-1);
        for(int i = 0; i<size-1; i++)
        {
            newArr[i] = (nums[i] + nums[i+1])%10;
        }
        return triangularSum(newArr);
    }
};