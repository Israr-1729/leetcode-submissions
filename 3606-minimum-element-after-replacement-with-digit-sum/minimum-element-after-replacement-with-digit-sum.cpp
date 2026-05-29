class Solution {
public:
    int minElement(vector<int>& nums) {

        int size = nums.size();
        int min = INT_MAX;
        for(int i = 0; i<size; i++)
        {
            int sum = 0;
            while(nums[i] != 0)
            {
                sum += nums[i]%10;
                nums[i]/=10;
            }
            if(sum<min)
            min = sum;
        }
        return min;
    }
};