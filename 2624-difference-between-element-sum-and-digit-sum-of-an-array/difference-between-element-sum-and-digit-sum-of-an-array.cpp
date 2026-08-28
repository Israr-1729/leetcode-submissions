class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        long long digitSum = 0;
        long long elementSum = 0;

        for(int i : nums)
        {
            elementSum += i;

            while(i)
            {
                digitSum += i % 10;
                i /= 10;
            }
        }
        return abs(digitSum - elementSum);
    }
};