class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int size = nums.size(); int counter = 0;
        for(int i = 0; i<size; i++)
        {
            int num = nums[i];
            while(num!=0)
            {
                if(num%10 == digit)
                counter++;
                num/=10;
            }
        }
        return counter;
    }
};