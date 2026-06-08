class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int sum = 0;
        int begin = 0; int end = 0; int counter = 0;
        while(begin<size)
        {
            sum = 0;
            end = begin;
            while(end<size)
            {
                sum += nums[end];
                if(sum==k)
                counter++;
                end++;
            }
            begin++;
        }
        return counter;
    }
};