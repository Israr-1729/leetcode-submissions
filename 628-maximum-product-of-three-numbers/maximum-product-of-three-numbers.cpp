class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        /*if(nums[0]*nums[1]>nums[size-1]*nums[size-2])
        return nums[0]*nums[1]*nums[size-1];

        else*/
        return max(nums[size-1]*nums[size-2]*nums[size-3], max(nums[0]*nums[1]*nums[2], nums[0]*nums[1]*nums[size-1]));
    }
};