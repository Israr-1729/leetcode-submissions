class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int size = nums.size();
        vector<int>numsAndReversed(size*2);
        for(int i = 0; i<size; i++)
        {
            numsAndReversed[i] = nums[i];
        }
        for(int i = size; i<size*2; i++)
        {
            int copy = nums[i-size];
            int reversed = 0;
            while(copy!=0)
            {
            reversed = reversed*10 + copy%10;
            copy/=10;
            }
            numsAndReversed[i] = reversed;
        }
        int count = 0;
        set<int> isSeen;
        for(int i = 0; i<size*2; i++)
        {
            isSeen.insert(numsAndReversed[i]);
        }
        return isSeen.size();
    }
};