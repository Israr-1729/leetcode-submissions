class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Use XOR operator.

        int a = nums[0];
        int size = nums.size();
        for(int i = 1; i<size; i++)
        {
            a = a^nums[i];
        }
        return a;
    }
};